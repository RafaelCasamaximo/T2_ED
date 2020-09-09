#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "padrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

void pnt(Lista* listas, int j, char* cb, char* cp){
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
                }
                else if(i == RETANGULO){
                    retanguloSetCorBorda(info, cb);
                    retanguloSetCorPreenchimento(info, cp);
                }
                else if(i == TEXTO){
                    textoSetCorBorda(info, cb);
                    textoSetCorPreenchimento(info, cp);
                }
                return;
            }
        }
    }
}

void pntAst(Lista* listas, int j, int k, char* cb, char* cp){
    
    for(int i = min(j, k); i <= max(j, k); i++){
        pnt(listas, i, cb, cp);
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

int iInt(Lista* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY){
    int id = 0;
    
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
                    return insideCirculo(x, y, circuloGetX(info), circuloGetY(info), circuloGetRaio(info));
                }
                else if(i == RETANGULO){
                    *centroDeMassaX = retanguloGetX(info) + (retanguloGetWidth(info) / 2);
                    *centroDeMassaY = retanguloGetY(info) + (retanguloGetHeight(info) / 2);
                    return insideRetangulo(x, y, retanguloGetX(info), retanguloGetY(info), retanguloGetWidth(info), retanguloGetHeight(info));
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

int oInt(Lista* listas, int j, int k, float* x, float* y, float* w, float* h){
    float vX[4] = {0, 0, 0, 0};
    float vY[4] = {0, 0, 0, 0};
    
    int overlay = -1;

    Info infoJ = NULL;
    int tipoJ = -1;
    Info infoK = NULL;
    int tipoK = -1;

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
        return overlay;
    }
    else if(tipoJ == RETANGULO && tipoK == RETANGULO){
        overlay = overlayRetanguloRetangulo(infoJ, infoK);
        return overlay;
    }
    else if(tipoJ == CIRCULO && tipoK == RETANGULO){
        overlay = overlayCirculoRetangulo(infoJ, infoK);
        return overlay;
    }
    else if(tipoJ == RETANGULO && tipoK == CIRCULO){
        overlay = overlayCirculoRetangulo(infoK, infoJ);
        return overlay;
    }
    return -1;
}

void del(Lista* listas, char* cep){
    for(int i = QUADRA; i <= RADIOBASE; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            char id[20];
            if(i == QUADRA){
                strcpy(id, quadraGetCep(getInfo(aux)));
            }
            else if(i == HIDRANTE){
                strcpy(id, hidranteGetId(getInfo(aux)));
            }
            else if(i == SEMAFORO){
                strcpy(id, semaforoGetId(getInfo(aux)));
            }
            else if(i == RADIOBASE){
                strcpy(id, radioBaseGetId(getInfo(aux)));
            }

            if(strcmp(id, cep) == 0){
                removeNode(listas[i], aux);
                return;
            }
        }
    }
}
