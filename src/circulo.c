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
    char* cb;
    char* cp;
}CirculoStruct;

Circulo criaCirculo(int id, float r, float x, float y, char* cb, char* cp){
    CirculoStruct* circ = (CirculoStruct*) malloc(sizeof(CirculoStruct));

    circ->id = id;
    circ->r = r;
    circ->x = x;
    circ->y = y;
    circ->cb = cb;
    circ->cp = cp;

    
    return circ;
}

//Setters
void setId(Circulo circulo, int id){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->id = id;
}
void setRaio(Circulo circulo, float r){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->r = r;
}
void setX(Circulo circulo, float x){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->x = x;
}
void setY(Circulo circulo, float y){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->y = y;
}
void setCorBorda(Circulo circulo, char cb[]){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->cb, cb);
}
void setCorPreenchimento(Circulo circulo, char cp[]){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->cp, cp);
}

//Getters
int getId(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->id;
}
float getRaio(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->r;
}
float getX(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->x;
}
float getY(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->y;
}
char* getCorBorda(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->cb;
}
char* getCorPreenchimento(Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->cp;
}

