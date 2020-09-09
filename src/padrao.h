#ifndef PADRAO__H_ 
#define PADRAO__H_

float distanciaQuadrada(float x1, float  y1, float  x2, float  y2);

//Calcula o min de 2 valores;
//a, b - valores especificados;
int min(int a, int b);

//Calcula o max de 2 valores;
//a, b - valores especificados;
int max(int a, int b);

//Calcula o min de 2 valores;
//a, b - valores especificados;
float minF(float a, float b);

//Calcula o max de 2 valores;
//a, b - valores especificados;
float maxF(float a, float b);

//Calcula o min de um vetor;
float minV(float v[], int tamanho);

//Calcula o max de um vetor;
float maxV(float v[], int tamanho);

#endif