#ifndef __HIDRANTE_H
#define __HIDRANTE_H

typedef void* Hidrante;

/*
Cria um hidrante
Pré: Atributos do hidrante (id, x e y)
Pós: Retorna o endereço do hidrante
*/
Hidrante criaHidrante(char* id, float x, float y);

//Setters
/*
Define algum atributo do hidrante
Pré: Atributo do hidrante referente deseja definir
Pós: nenhum
*/
void hidranteSetId(Hidrante hidrante, char* id);
void hidranteSetX(Hidrante hidrante, float x);
void hidranteSetY(Hidrante hidrante, float y);

//Getters
/*Obtém algum atributo do hidrante
Pre: Hidrante
Pós: Retorna o atributo em questão
*/
char* hidranteGetId(Hidrante hidrante);
float hidranteGetX(Hidrante hidrante);
float hidranteGetY(Hidrante hidrante);


#endif