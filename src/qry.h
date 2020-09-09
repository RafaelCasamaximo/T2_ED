#ifndef QRY__H_
#define QRY__H_

#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"

void pnt(Lista* listas, int j, char* cb, char* cp);
void pntAst(Lista* listas, int j, int k, char* cb, char* cp);

void delf(Lista* listas, int j);
void delfAst(Lista* listas, int j, int k);

int insideCirculo(float x, float y, float cx, float cy, float r);
int insideRetangulo(float x, float y, float rx, float ry, float rw, float rh);

int iInt(Lista* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY);

int overlayCirculoRetangulo(Circulo c, Retangulo r);
int overlayCirculoCirculo(Circulo c1, Circulo c2);
int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2);

int oInt(Lista* listas, int j, int k, float* x, float* y, float* w, float* h);

void del(Lista* listas, char* cep);

#endif