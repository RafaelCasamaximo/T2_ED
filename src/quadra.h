#ifndef __QUADRA_H
#define __QUADRA_H

typedef void* Quadra;

Quadra criaQuadra(char* cep, float x, float y, float w, float h, char* cb, char* cp, int arredondado);

//Setters
void quadraSetCep(Quadra quadra, char* cep);
void quadraSetX(Quadra quadra, float x);
void quadraSetY(Quadra quadra, float y);
void quadraSetWidth(Quadra quadra, float w);
void quadraSetHeight(Quadra quadra, float h);
void quadraSetCorBorda(Quadra quadra, char* cb);
void quadraSetCorPreenchimento(Quadra quadra, char* cp);
void quadraSetArredondado(Quadra quadra, int arredondado);

//Getters
char* quadraGetCep(Quadra quadra);
float quadraGetX(Quadra quadra);
float quadraGetY(Quadra quadra);
float quadraGetWidth(Quadra quadra);
float quadraGetHeight(Quadra quadra);
char* quadraGetCorBorda(Quadra quadra);
char* quadraGetCorPreenchimento(Quadra quadra);
int quadraGetArredondado(Quadra quadra);
float quadraGetArea(Quadra quadra);

#endif