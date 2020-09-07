#ifndef __SEMAFORO_H
#define __SEMAFORO_H

typedef void* Semaforo; //Cria um tipo Semaforo que guarda void*

Semaforo criaSemaforo(char* id, float x, float y); //Cria um novo Semaforo

//Setters
void semaforoSetId(Semaforo semaforo, char* id); //Seta um novo valor para o id do Semaforo
void semaforoSetX(Semaforo semaforo, float x);
void semaforoSetY(Semaforo semaforo, float y);

//Getters
char* semaforoGetId(Semaforo semaforo); //Retorna o valor atual do id do Semaforo
float semaforoGetX(Semaforo semaforo);
float semaforoGetY(Semaforo semaforo);

#endif