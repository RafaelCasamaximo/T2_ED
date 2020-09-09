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

#endif