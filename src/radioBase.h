#ifndef __RADIOBASE_H
#define __RADIOBASE_H

typedef void* RadioBase;

/*
Cria uma radio base (torre de telefonia)
Pre: Atributos da radio base (id, x, y)
Pós: Retorna o endereço da radio base
*/ 
RadioBase criaRadioBase(char* id, float x, float y);

//Setters
/*
Define algum atributo da radio base
Pre: Atributo da radio base referente que deseja-se definir
Pós: Nenhum
*/
void radioBaseSetId(RadioBase radiobase, char* id);
void radioBaseSetX(RadioBase radiobase, float x);
void radioBaseSetY(RadioBase radiobase, float y);

//Getters
/*
Obtém algum atributo da radio base
Pre: Radio base
Pós: Retorna o atributo em questão
*/
char* radioBaseGetId(RadioBase radiobase);
float radioBaseGetX(RadioBase radiobase);
float radioBaseGetY(RadioBase radiobase);

#endif