#include <stdio.h>
#include <stdlib.h>
#include "hidrante.h"

typedef struct hidrante{
    int id;
    float x;
    float y;
}HidranteStruct;

Hidrante criaHidrante(int id, float x, float y){
    HidranteStruct* hid = (HidranteStruct*) malloc(sizeof(HidranteStruct));

    hid->id = id;
    hid->x = x;
    hid->y = y;

    return hid;
}

//Setters
void hidranteSetId(Hidrante hidrante, int id){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->id = id;
}
void hidranteSetX(Hidrante hidrante, float x){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->x = x;
}
void hidranteSetY(Hidrante hidrante, float y){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->y = y;
}

//Getters
int hidranteGetId(Hidrante hidrante){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->id;
}
float hidranteGetX(Hidrante hidrante){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->x;
}
float hidranteGetY(Hidrante hidrante){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->y;
}
