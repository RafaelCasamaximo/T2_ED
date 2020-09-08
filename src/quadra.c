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
}QuadraStruct;

Quadra criaQuadra(char* cep, float x, float y, float w, float h){
    QuadraStruct* qad = (QuadraStruct*) malloc(sizeof(QuadraStruct));

    strcpy(qad->cep, cep);
    qad->x = x;
    qad->y = y;
    qad->w = w;
    qad->h = h;

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
