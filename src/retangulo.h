#ifndef __RETANGULO_H
#define __RETANGULO_H

typedef void* Retangulo;

Retangulo criaRetangulo(int id, float x, float y, float w, float h, char* cb, char* cp);

//Setters
void retanguloSetId(Retangulo retangulo, int id);
void retanguloSetX(Retangulo retangulo, float x);
void retanguloSetY(Retangulo retangulo, float y);
void retanguloSetWidth(Retangulo retangulo, float w);
void retanguloSetHeight(Retangulo retangulo, float h);
void retanguloSetCorBorda(Retangulo retangulo, char* cb);
void retanguloSetCorPreenchimento(Retangulo retangulo, char* cp);


//Getters
int retanguloGetId(Retangulo retangulo);
float retanguloGetX(Retangulo retangulo);
float retanguloGetY(Retangulo retangulo);
float retanguloGetWidth(Retangulo retangulo);
float retanguloGetHeight(Retangulo retangulo);
char* retanguloGetCorBorda(Retangulo retangulo);
char* retanguloGetCorPreenchimento(Retangulo retangulo);


#endif