#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidrante.h"

typedef struct hidrante{
    char id[20];
    float x;
    float y;
}HidranteStruct;

Hidrante criaHidrante(char* id, float x, float y){
    HidranteStruct* hid = (HidranteStruct*) malloc(sizeof(HidranteStruct));
    
    strcpy(hid->id, id);
    hid->x = x;
    hid->y = y;

    return hid;
}

//Setters
void hidranteSetId(Hidrante hidrante, char* id){
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->id, id);
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
char* hidranteGetId(Hidrante hidrante){
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
