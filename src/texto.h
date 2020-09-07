#ifndef __TEXTO_H
#define __TEXTO_H

typedef void* Texto;

Texto criaTexto(int id, float x, float y, char* cb, char* cp, char* txt);

//Setters
void textoSetId(Texto texto, int id);
void textoSetX(Texto texto, float x);
void textoSetY(Texto texto, float y);
void textoSetCorBorda(Texto texto, char* cb);
void textoSetCorPreenchimento(Texto texto, char* cp);
void textoSetTexto(Texto texto, char* txt);

//Getters
int textoGetId(Texto texto);
float textoGetX(Texto texto);
float textoGetY(Texto texto);
char* textoGetCorBorda(Texto texto);
char* textoGetCorPreenchimento(Texto texto);
char* textoGetTexto(Texto texto);


#endif