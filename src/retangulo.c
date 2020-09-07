#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

typedef struct retangulo{
    int id;
    float x;
    float y;
    float w;
    float h;
    char* cb;
    char* cp;
}RetanguloStruct;

Retangulo criaRetangulo(int id, float x, float y, float w, float h, char* cb, char* cp){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->id = id;
    ret->x = x;
    ret->y = y;
    ret->w = w;
    ret->h = h;
    ret->cb = cb;
    ret->cp = cp;
    
    return ret;
}    

//Setters
void retanguloSetId(Retangulo retangulo, int id){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->id = id;
}

void retanguloSetX(Retangulo retangulo, float x){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->x = x;
}

void retanguloSetY(Retangulo retangulo, float y){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->y = y;
}

void retanguloSetWidth(Retangulo retangulo, float w){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->w = w;
}

void retanguloSetHeight(Retangulo retangulo, float h){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->h = h;
}

void retanguloSetCorBorda(Retangulo retangulo, char* cb){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->cb = cb;
}

void retanguloSetCorPreenchimento(Retangulo retangulo, char* cp){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->cp = cp;
}

//Getters
int retanguloGetId(Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->id;
}
float retanguloGetX(Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->x;
}
float retanguloGetY(Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->y;
}
float retanguloGetWidth(Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->w;
}
float retanguloGetHeight(Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->h;
}
char* retanguloGetCorBorda(Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->cb;
}
char* retanguloGetCorPreenchimento(Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->cp;
}










