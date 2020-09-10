#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadra.h"

typedef struct quadra{
    char cep[20];
    float x;
    float y;
    float w;
    float h;
    char cb[22];
    char cp[22];
    int arredondado;
}QuadraStruct;

Quadra criaQuadra(char* cep, float x, float y, float w, float h, char* cb, char* cp, int arredondado){
    QuadraStruct* qad = (QuadraStruct*) malloc(sizeof(QuadraStruct));

    strcpy(qad->cep, cep);
    qad->x = x;
    qad->y = y;
    qad->w = w;
    qad->h = h;
    strcpy(qad->cb, cb);
    strcpy(qad->cp, cp);
    qad->arredondado = arredondado;

    return qad; 
}

//Setters
void quadraSetCep(Quadra quadra, char* cep){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    strcpy(qad->cep, cep);
}
void quadraSetX(Quadra quadra, float x){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    qad->x = x;
}
void quadraSetY(Quadra quadra, float y){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    qad->y = y;
}
void quadraSetWidth(Quadra quadra, float w){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    qad->w = w;
}
void quadraSetHeight(Quadra quadra, float h){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    qad->h = h;
}
void quadraSetCorBorda(Quadra quadra, char* cb){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    strcpy(qad->cb, cb);
}
void quadraSetCorPreenchimento(Quadra quadra, char* cp){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    strcpy(qad->cp, cp);
}
void quadraSetArredondado(Quadra quadra, int arredondado){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    qad->arredondado = arredondado;
}

//Getters
char* quadraGetCep(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->cep;
}
float quadraGetX(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->x;
}
float quadraGetY(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->y;
}
float quadraGetWidth(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->w;
}
float quadraGetHeight(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->h;
}
char* quadraGetCorBorda(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->cb;
}
char* quadraGetCorPreenchimento(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->cp;
}

int quadraGetArredondado(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return qad->arredondado;
}

float quadraGetArea(Quadra quadra){
    QuadraStruct* qad = (QuadraStruct*) quadra;
    return (qad->w * qad->h);
}