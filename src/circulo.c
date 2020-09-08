#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

//typedef tipo novoTipo
typedef struct circulo{
    int id;
    float r;
    float x;
    float y;
    char cb[22];
    char cp[22];
}CirculoStruct;

Circulo criaCirculo(int id, float r, float x, float y, char* cb, char* cp){
    CirculoStruct* circ = (CirculoStruct*) malloc(sizeof(CirculoStruct));

    circ->id = id;
    circ->r = r;
    circ->x = x;
    circ->y = y;
    strcpy(circ->cb, cb);
    strcpy(circ->cp, cp);
    
    return circ;
}

//Setters
void circuloSetId(Circulo circulo, int id){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->id = id;
}
void circuloSetRaio(Circulo circulo, float r){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->r = r;
}
void circuloSetX(Circulo circulo, float x){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->x = x;
}
void circuloSetY(Circulo circulo, float y){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->y = y;
}
void circuloSetCorBorda(Circulo circulo, char* cb){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->cb, cb);
}
void circuloSetCorPreenchimento(Circulo circulo, char* cp){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->cp, cp);
}

//Getters
int circuloGetId(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->id;
}
float circuloGetRaio(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->r;
}
float circuloGetX(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->x;
}
float circuloGetY(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->y;
}
char* circuloGetCorBorda(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->cb;
}
char* circuloGetCorPreenchimento(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->cp;
}

