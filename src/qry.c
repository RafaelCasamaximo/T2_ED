#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "linha.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "padrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

void pnt(Lista* listas, int j, char* cb, char* cp, FILE* fileTxt){
    int id = 0;

    Info info;

    for(int i = 0; i < 3; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            info = getInfo(aux);
            if(i == CIRCULO){
                id = circuloGetId(info);
            }
            else if(i == RETANGULO){
                id = retanguloGetId(info);
            }
            else if(i == TEXTO){
                id = textoGetId(info);
            }
            if(id == j){
                if(i == CIRCULO){
                    circuloSetCorBorda(info, cb);
                    circuloSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)));
                }
                else if(i == RETANGULO){
                    retanguloSetCorBorda(info, cb);
                    retanguloSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)));
                }
                else if(i == TEXTO){
                    textoSetCorBorda(info, cb);
                    textoSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, textoGetX(getInfo(aux)), textoGetY(getInfo(aux)));
                }
                return;
            }
        }
    }
}

void pntAst(Lista* listas, int j, int k, char* cb, char* cp, FILE* fileTxt){
    
    for(int i = min(j, k); i <= max(j, k); i++){
        pnt(listas, i, cb, cp, fileTxt);
    }
}
 

void delf(Lista* listas, int j){
    Info info;
    int id;
    
    for(int i = 0; i < 3; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            info = getInfo(aux);
            if(i == CIRCULO){
                id = circuloGetId(info);
            }
            else if(i == RETANGULO){
                id = retanguloGetId(info);
            }
            else if(i == TEXTO){
                id = textoGetId(info);
            }
            if(id == j){
                if(i == TEXTO){
                    textoDeletaTexto(info);
                }
                removeNode(listas[i], aux);
                return;
            }
        }
    }
}

void delfAst(Lista* listas, int j, int k){
    for(int i = min(j, k); i <= max(j, k); i++){
        delf(listas, i);
    }
}

int insideCirculo(float x, float y, float cx, float cy, float r){
    return (distanciaQuadrada(x, y, cx, cy) < r * r ? 1 : 0);
}

int insideRetangulo(float x, float y, float rx, float ry, float rw, float rh){
    if((x == rx || x == rx+rw) || (y == ry || y == ry + rh)){
        return 2;
    }
    return ((x > rx && x < rx + rw) && (y > ry && y < ry + rh) ? 1 : 0);
}

int iInt(Lista* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY, FILE* fileTxt){
    int id = 0;
    
    fprintf(fileTxt, "i? %d %f %f\n", j, x, y);

    for(int i = 0; i < 2; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            Info info = getInfo(aux);
            if(i == CIRCULO){
                id = circuloGetId(info);
            }
            else if(i == RETANGULO){
                id = retanguloGetId(info);
            }
            if(id == j){
                if(i == CIRCULO){
                    *centroDeMassaX = circuloGetX(info);
                    *centroDeMassaY = circuloGetY(info);
                    int resultado = insideCirculo(x, y, circuloGetX(info), circuloGetY(info), circuloGetRaio(info));
                    fprintf(fileTxt, "CIRCULO %s\n\n", resultado == 1 ? "CONTÉM" : "NÃO CONTÉM");
                    return resultado;
                }
                else if(i == RETANGULO){
                    *centroDeMassaX = retanguloGetX(info) + (retanguloGetWidth(info) / 2);
                    *centroDeMassaY = retanguloGetY(info) + (retanguloGetHeight(info) / 2);
                    int resultado = insideRetangulo(x, y, retanguloGetX(info), retanguloGetY(info), retanguloGetWidth(info), retanguloGetHeight(info));
                    fprintf(fileTxt, "CIRCULO %s\n\n", resultado == 1 ? "CONTÉM" : "NÃO CONTÉM");
                    return resultado;
                }
            }
        }
    }
    return -1;
}
int overlayCirculoRetangulo(Circulo c, Retangulo r){
    float dX = circuloGetX(c) - maxF(retanguloGetX(r), minF(circuloGetX(c), retanguloGetX(r) + retanguloGetWidth(r)));
    float dY = circuloGetY(c) - maxF(retanguloGetY(r), minF(circuloGetY(c), retanguloGetY(r) + retanguloGetHeight(r)));
    if((dX * dX + dY * dY) <= (circuloGetRaio(c) * circuloGetRaio(c))){
        return 1;
    } 
    return 0;
}

int overlayCirculoCirculo(Circulo c1, Circulo c2){
    if(distanciaQuadrada(circuloGetX(c1), circuloGetY(c1), circuloGetX(c2), circuloGetY(c2)) <= (circuloGetRaio(c1) + circuloGetRaio(c2)) * (circuloGetRaio(c1) + circuloGetRaio(c2))){
        return 1;
    }
    return 0;
}

int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2){

    int inside = -1;

    float r1X = retanguloGetX(r1);
    float r1Y = retanguloGetY(r1);
    float r1W = retanguloGetWidth(r1);
    float r1H = retanguloGetHeight(r1);

    float r2X = retanguloGetX(r2);
    float r2Y = retanguloGetY(r2);
    float r2W = retanguloGetWidth(r2);
    float r2H = retanguloGetHeight(r2);

    //Existe algum ponto do r1 contido no r2?
    inside = insideRetangulo(r1X, r1Y, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r1X + r1W, r1Y, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r1X, r1Y + r1H, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r1X + r1W, r1Y + r1H, r2X, r2Y, r2W, r2H);
    if(inside == 1 || inside == 2){
        return 1;
    }

    //Existe algum ponto do r2 contido no r1?
    inside = insideRetangulo(r2X, r2Y, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r2X + r2W, r2Y, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r2X, r2Y + r2H, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    inside = insideRetangulo(r2X + r2W, r2Y + r2H, r1X, r1Y, r1W, r1H);
    if(inside == 1 || inside == 2){
        return 1;
    }
    
    return 0;
}

int oInt(Lista* listas, int j, int k, float* x, float* y, float* w, float* h, FILE* fileTxt){
    float vX[4] = {0, 0, 0, 0};
    float vY[4] = {0, 0, 0, 0};
    
    int overlay = -1;

    Info infoJ = NULL;
    int tipoJ = -1;
    Info infoK = NULL;
    int tipoK = -1;

    fprintf(fileTxt, "o? %d %d\n", j, k);

    int idAux = 0;

    for(int i = 0; i < 2; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            if(i == CIRCULO){
                idAux = circuloGetId(getInfo(aux));
            }
            else if(i == RETANGULO){
                idAux = retanguloGetId(getInfo(aux));
            }
            if(idAux == j){
                infoJ = getInfo(aux);
                tipoJ = i;
            }
            if(idAux == k){
                infoK = getInfo(aux);
                tipoK = i;
            }
        }
    }

    if(tipoJ == CIRCULO){
        vX[0] = circuloGetX(infoJ) + circuloGetRaio(infoJ);
        vX[1] = circuloGetX(infoJ) - circuloGetRaio(infoJ);
        vY[0] = circuloGetY(infoJ) + circuloGetRaio(infoJ);
        vY[1] = circuloGetY(infoJ) - circuloGetRaio(infoJ);
    }
    else if(tipoJ == RETANGULO){
        vX[0] = retanguloGetX(infoJ);
        vX[1] = retanguloGetX(infoJ) + retanguloGetWidth(infoJ);
        vY[0] = retanguloGetY(infoJ);
        vY[1] = retanguloGetY(infoJ) + retanguloGetHeight(infoJ);
    }

    if(tipoK == CIRCULO){
        vX[2] = circuloGetX(infoK) + circuloGetRaio(infoK);
        vX[3] = circuloGetX(infoK) - circuloGetRaio(infoK);
        vY[2] = circuloGetY(infoK) + circuloGetRaio(infoK);
        vY[3] = circuloGetY(infoK) - circuloGetRaio(infoK);
    }
    else if(tipoK == RETANGULO){
        vX[2] = retanguloGetX(infoK);
        vX[3] = retanguloGetX(infoK) + retanguloGetWidth(infoK);
        vY[2] = retanguloGetY(infoK);
        vY[3] = retanguloGetY(infoK) + retanguloGetHeight(infoK);
    }

    *x = minV(vX, 4);
    *y = minV(vY, 4);
    *w = maxV(vX, 4) - *x;
    *h = maxV(vY, 4) - *y;

    if(tipoJ == CIRCULO && tipoK == CIRCULO){
        overlay = overlayCirculoCirculo(infoJ, infoK);
        fprintf(fileTxt, "CIRCULO CIRCULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");
        return overlay;
    }
    else if(tipoJ == RETANGULO && tipoK == RETANGULO){
        overlay = overlayRetanguloRetangulo(infoJ, infoK);
        fprintf(fileTxt, "RETANGULO RETANGULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");
        return overlay;
    }
    else if(tipoJ == CIRCULO && tipoK == RETANGULO){
        overlay = overlayCirculoRetangulo(infoJ, infoK);
        fprintf(fileTxt, "CIRCULO RETANGULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");

        return overlay;
    }
    else if(tipoJ == RETANGULO && tipoK == CIRCULO){
        overlay = overlayCirculoRetangulo(infoK, infoJ);
        fprintf(fileTxt, "RETANGULO CIRCULO %s\n\n", overlay == 1 ? "SOBREPÕE" : "NÃO SOBREPÕE");
        return overlay;
    }
    return -1;
}

void del(Lista* listas, char* cep){
    for(int i = QUADRA; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            char id[20];
            float x = 0, y = 0;
            if(i == QUADRA){
                strcpy(id, quadraGetCep(getInfo(aux)));
                x = quadraGetX(getInfo(aux));
                y = quadraGetY(getInfo(aux));
            }
            else if(i == HIDRANTE){
                strcpy(id, hidranteGetId(getInfo(aux)));
                x = hidranteGetX(getInfo(aux));
                y = hidranteGetY(getInfo(aux));
            }
            else if(i == SEMAFORO){
                strcpy(id, semaforoGetId(getInfo(aux)));
                x = semaforoGetX(getInfo(aux));
                y = semaforoGetY(getInfo(aux));
            }
            else if(i == RADIOBASE){
                strcpy(id, radioBaseGetId(getInfo(aux)));
                x = radioBaseGetX(getInfo(aux));
                y = radioBaseGetY(getInfo(aux));
            }

            if(strcmp(id, cep) == 0){
                insert(listas[LINHA], criaLinha(x, y, x, 0, 0, 0, id));
                removeNode(listas[i], aux);
                return;
            }
        }
    }
}

void cbq(Lista* listas, float x, float y, float r, char* cb){
    float xQuadra = 0, yQuadra = 0, wQuadra = 0, hQuadra = 0;
    
    for(Node aux = getFirst(listas[QUADRA]); aux != NULL; aux = getNext(aux)){
        xQuadra = quadraGetX(getInfo(aux));
        yQuadra = quadraGetY(getInfo(aux));
        wQuadra = quadraGetWidth(getInfo(aux));
        hQuadra = quadraGetHeight(getInfo(aux));

        /*
        x,y 
        x + w, y
        x, y + h
        x + w, y + h
        */
        int insideP1 = insideCirculo(xQuadra, yQuadra, x, y, r);
        int insideP2 = insideCirculo(xQuadra + wQuadra, yQuadra, x, y, r);
        int insideP3 = insideCirculo(xQuadra, yQuadra + hQuadra, x, y, r);
        int insideP4 = insideCirculo(xQuadra + wQuadra, yQuadra + hQuadra, x, y, r);
        
        if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
            quadraSetCorBorda(getInfo(aux), cb);
        }
    }
}

void dq(Lista* listas, char* id, float r, int hashtag, int identificadorFigura){
    char idAux[20];
    float x = 0;
    float y = 0;

    for(int i = HIDRANTE; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            if(i == SEMAFORO){
                strcpy(idAux, semaforoGetId(getInfo(aux)));
            }
            else if(i == HIDRANTE){
                strcpy(idAux, hidranteGetId(getInfo(aux)));
            }
            else if(i == RADIOBASE){
                strcpy(idAux, radioBaseGetId(getInfo(aux)));
            }
            if(strcmp(idAux, id) == 0){
                if(i == SEMAFORO){
                    x = semaforoGetX(getInfo(aux));
                    y = semaforoGetY(getInfo(aux));
                }
                else if(i == HIDRANTE){
                    x = hidranteGetX(getInfo(aux));
                    y = hidranteGetY(getInfo(aux));
                }
                else if(i == RADIOBASE){
                    x = radioBaseGetX(getInfo(aux));
                    y = radioBaseGetY(getInfo(aux));
                }
                if(hashtag == 1){

                    Node auxDelete = getFirst(listas[QUADRA]);
                    while(auxDelete != NULL){
                        float xQuadra = quadraGetX(getInfo(auxDelete));
                        float yQuadra = quadraGetY(getInfo(auxDelete));
                        float wQuadra = quadraGetWidth(getInfo(auxDelete));
                        float hQuadra = quadraGetHeight(getInfo(auxDelete));

                        int insideP1 = insideCirculo(xQuadra, yQuadra, x, y, r);
                        int insideP2 = insideCirculo(xQuadra + wQuadra, yQuadra, x, y, r);
                        int insideP3 = insideCirculo(xQuadra, yQuadra + hQuadra, x, y, r);
                        int insideP4 = insideCirculo(xQuadra + wQuadra, yQuadra + hQuadra, x, y, r);

                        Node tempAux = getNext(auxDelete);
                        if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
                        removeNode(listas[QUADRA], auxDelete);
                        }
                        auxDelete = tempAux;
                    }
                }
                else if(hashtag == 0){
                    for(Node auxMudaCor = getFirst(listas[QUADRA]); auxMudaCor != NULL; auxMudaCor = getNext(auxMudaCor)){
                        float xQuadra = quadraGetX(getInfo(auxMudaCor));
                        float yQuadra = quadraGetY(getInfo(auxMudaCor));
                        float wQuadra = quadraGetWidth(getInfo(auxMudaCor));
                        float hQuadra = quadraGetHeight(getInfo(auxMudaCor));

                        int insideP1 = insideCirculo(xQuadra, yQuadra, x, y, r);
                        int insideP2 = insideCirculo(xQuadra + wQuadra, yQuadra, x, y, r);
                        int insideP3 = insideCirculo(xQuadra, yQuadra + hQuadra, x, y, r);
                        int insideP4 = insideCirculo(xQuadra + wQuadra, yQuadra + hQuadra, x, y, r);

                        if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
                            quadraSetArredondado(getInfo(auxMudaCor), 1);
                            quadraSetCorBorda(getInfo(auxMudaCor), "olive");
                            quadraSetCorPreenchimento(getInfo(auxMudaCor), "beige");
                        }

                    }
                }
                insert(listas[CIRCULO], criaCirculo(identificadorFigura, 7, x, y, "blue", "none"));
                insert(listas[CIRCULO], criaCirculo(identificadorFigura - 1, 11, x, y, "blue", "none"));
                insert(listas[CIRCULO], criaCirculo(identificadorFigura - 2, r, x, y, "blue", "none"));
            }
        }
    }
}

void car(Lista* listas, float x, float y, float w, float h, int id){
    float areaTotal = 0;
    char areaFiguraString[10];
    char areaString[22];

    int counter = id;

    for(int i = QUADRA; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            counter--;
            if(i == QUADRA){
                float xQuadra = quadraGetX(getInfo(aux));
                float yQuadra = quadraGetY(getInfo(aux));
                float wQuadra = quadraGetWidth(getInfo(aux));
                float hQuadra = quadraGetHeight(getInfo(aux));

                int insideP1 = insideRetangulo(xQuadra, yQuadra, x, y, w, h);
                int insideP2 = insideRetangulo(xQuadra + wQuadra, yQuadra, x, y, w, h);
                int insideP3 = insideRetangulo(xQuadra, yQuadra + hQuadra, x, y, w, h);
                int insideP4 = insideRetangulo(xQuadra + wQuadra, yQuadra + hQuadra, x, y, w, h);

                if(insideP1 == 1 && insideP2 == 1 && insideP3 == 1 && insideP4 == 1){
                    areaTotal += quadraGetArea(getInfo(aux));
                    sprintf(areaFiguraString, "%f", quadraGetArea(getInfo(aux)));
                    insert(listas[TEXTO], criaTexto(counter, xQuadra + (wQuadra/2), yQuadra + (hQuadra/2), "seashell", "black", areaFiguraString, 10));
                }
            }
            else if(i == HIDRANTE){
                float xH = hidranteGetX(getInfo(aux));
                float yH = hidranteGetY(getInfo(aux));
                int p = insideRetangulo(xH, yH, x, y, w, h);

                if(p == 1){
                    areaTotal += 28.27;
                    insert(listas[TEXTO], criaTexto(counter, xH , yH, "seashell", "black", "28.27", 6));
                }
            }
            else if(i == SEMAFORO){
                float xS = semaforoGetX(getInfo(aux));
                float yS = semaforoGetY(getInfo(aux));
                int p = insideRetangulo(yS, yS, x, y, w, h);
                if(p == 1){
                    areaTotal += 28.27;
                    insert(listas[TEXTO], criaTexto(counter, xS , yS, "seashell", "black", "28.27", 6));
                }
            }
            else if(i == RADIOBASE){
                float xR = semaforoGetX(getInfo(aux));
                float yR = semaforoGetY(getInfo(aux));
                int p = insideRetangulo(xR, yR, x, y, w, h);
                if(p == 1){
                    areaTotal += 28.27;
                    insert(listas[TEXTO], criaTexto(counter, xR , yR, "seashell", "black", "28.27", 6));
                }
            }
        }
    }

    sprintf(areaString, "%f", areaTotal);
    insert(listas[RETANGULO], criaRetangulo(counter-50, x, y, w, h, "black", "none", 0));
    insert(listas[LINHA], criaLinha(x, y, x, 0, 0, 0, areaString));
}