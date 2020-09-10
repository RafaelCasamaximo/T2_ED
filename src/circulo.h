#ifndef __CIRCULO_H
#define __CIRCULO_H

typedef void* Circulo;

/*
Cria um circulo
Pre: Atributos do circulo (id, raio, x, y, cor da borda e cor de preenchimento)
Pós: Retorna o endereço do circulo
*/ 
Circulo criaCirculo(int id, float r, float x, float y, char* cb, char* cp);

//Setters
/*
Define algum atributo do circulo
Pre: Atributo do circulo referente que deseja-se definir
Pós: Nenhum
*/
void circuloSetId(Circulo circulo, int id);
void circuloSetRaio(Circulo circulo, float r);
void circuloSetX(Circulo circulo, float x);
void circuloSetY(Circulo circulo, float y);
void circuloSetCorBorda(Circulo circulo, char* cb);
void circuloSetCorPreenchimento(Circulo circulo, char* cp);

//Getters
/*
Obtém algum atributo do circulo
Pre: Circulo
Pós: Retorna o atributo em questão
*/
int circuloGetId(Circulo circulo);
float circuloGetRaio(Circulo circulo);
float circuloGetX(Circulo circulo);
float circuloGetY(Circulo circulo);
char* circuloGetCorBorda(Circulo circulo);
char* circuloGetCorPreenchimento(Circulo circulo);

#endif