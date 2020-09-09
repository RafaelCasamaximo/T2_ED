#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
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
                free(aux);
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