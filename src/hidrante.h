#ifndef __HIDRANTE_H
#define __HIDRANTE_H

typedef void* Hidrante;

Hidrante criaHidrante(int id, float x, float y);

//Setters
void hidranteSetId(Hidrante hidrante, int id);
void hidranteSetX(Hidrante hidrante, float x);
void hidranteSetY(Hidrante hidrante, float y);

//Getters
int hidranteGetId(Hidrante hidrante);
float hidranteGetX(Hidrante hidrante);
float hidranteGetY(Hidrante hidrante);


#endif