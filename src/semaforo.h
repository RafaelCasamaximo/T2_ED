#ifndef __SEMAFORO_H
#define __SEMAFORO_H

typedef void* Semaforo; //Cria um tipo Semaforo que guarda void*

/*
Cria um semaforo
Pre: Atributos do semaforo (id, x, y)
Pós: Retorna o endereço do semaforo
*/ 
Semaforo criaSemaforo(char* id, float x, float y); //Cria um novo Semaforo

//Setters
/*
Define algum atributo do semaforo
Pre: Atributo do semaforo referente que deseja-se definir
Pós: Nenhum
*/
void semaforoSetId(Semaforo semaforo, char* id); //Seta um novo valor para o id do Semaforo
void semaforoSetX(Semaforo semaforo, float x);
void semaforoSetY(Semaforo semaforo, float y);

//Getters
/*
Obtém algum atributo do semaforo
Pre: Semaforo
Pós: Retorna o atributo em questão
*/
char* semaforoGetId(Semaforo semaforo); //Retorna o valor atual do id do Semaforo
float semaforoGetX(Semaforo semaforo);
float semaforoGetY(Semaforo semaforo);

#endif