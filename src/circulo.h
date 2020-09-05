#ifndef __CIRCULO_H
#define __CIRCULO_H

typedef void* Circulo;

/* Cria um circulo
* Pre: variaveis iniciais do circulo
* Pro: endereço do circulo
*/ 
Circulo criaCirculo(int id, float r, float x, float y, char* cb, char* cp);

//Setters
void setId(Circulo circulo, int id);
void setRaio(Circulo circulo, float r);
void setX(Circulo circulo, float x);
void setY(Circulo circulo, float y);
void setCorBorda(Circulo circulo, char cb[]);
void setCorPreenchimento(Circulo circulo, char cp[]);

//Getters
int getId(Circulo circulo);
float getRaio(Circulo circulo);
float getX(Circulo circulo);
float getY(Circulo circulo);
char* getCorBorda(Circulo circulo);
char* getCorPreenchimento(Circulo circulo);

#endif