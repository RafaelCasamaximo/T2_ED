#ifndef __RETANGULO_H
#define __RETANGULO_H

typedef void* Retangulo;

Retangulo criaRetangulo(int id, float x, float y, float w, float h, char* cb, char* cp);

//Setters
void setId(Retangulo retangulo, int id);
void setX(Retangulo retangulo, float x);
void setY(Retangulo retangulo, float y);
void setWidth(Retangulo retangulo, float w);
void setHeight(Retangulo retangulo, float h);
void setCorBorda(Retangulo retangulo, char* cb);
void setCorPreenchimento(Retangulo retangulo, char* cp);


//Getters
int getId(Retangulo retangulo);
float getX(Retangulo retangulo);
float getY(Retangulo retangulo);
float getWidth(Retangulo retangulo);
float getHeight(Retangulo retangulo);
char* getCorBorda(Retangulo retangulo);
char* getCorPreenchimento(Retangulo retangulo);


#endif