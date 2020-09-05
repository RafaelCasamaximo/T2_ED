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

Retangulo criaRetangulo(int id, float x, float y, float w, float h, char *cb, char *cp){
    RetanguloStruct *ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
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
void setId(Retangulo retangulo, int id){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->id = id;
}

void setX(Retangulo retangulo, float x){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->x = x;
}

void setY(Retangulo retangulo, float y){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->y = y;
}

void setWidth(Retangulo retangulo, float w){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->w = w;
}

void setHeight(Retangulo retangulo, float h){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->h = h;
}

void setCorBorda(Retangulo retangulo, char* cb){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->cb = cb;
}

void setCorPreenchimento(Retangulo retangulo, char* cp){
    RetanguloStruct* ret = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    ret->cp = cp;
}

//Getters
int getId(Retangulo retangulo){
    RetanguloStruct *ret = (RetanguloStruct*) retangulo;
    return ret->id;
}
float getX(Retangulo retangulo){
    RetanguloStruct *ret = (RetanguloStruct*) retangulo;
    return ret->x;
}
float getY(Retangulo retangulo){
    RetanguloStruct *ret = (RetanguloStruct*) retangulo;
    return ret->y;
}
float getWidth(Retangulo retangulo){
    RetanguloStruct *ret = (RetanguloStruct*) retangulo;
    return ret->w;
}
float getHeight(Retangulo retangulo){
    RetanguloStruct *ret = (RetanguloStruct*) retangulo;
    return ret->h;
}
char* getCorBorda(Retangulo retangulo){
    RetanguloStruct *ret = (RetanguloStruct*) retangulo;
    return ret->cb;
}
char* getCorPreenchimento(Retangulo retangulo){
    RetanguloStruct *ret = (RetanguloStruct*) retangulo;
    return ret->cp;
}










