#ifndef LINHA__H_
#define LINHA__H_

typedef void* Linha;

Linha criaLinha(float x1, float y1, float x2, float y2, int pntInicial, int interna);

//Setters
void linhaSetX1(Linha linha, float x1);
void linhaSetY1(Linha linha, float y1);
void linhaSetX2(Linha linha, float x2);
void linhaSetY2(Linha linha, float y2);
void linhaSetPntInicial(Linha linha, int pntInicial);
void linhaSetInterna(Linha linha, int interna);

//Getters
float linhaGetX1(Linha linha);
float linhaGetY1(Linha linha);
float linhaGetX2(Linha linha);
float linhaGetY2(Linha linha);
int linhaGetPntInicial(Linha linha);
int linhaGetInterna(Linha linha);

#endif