#ifndef __RETANGULO_H
#define __RETANGULO_H

typedef void* Retangulo;

/*
Cria um retangulo
Pre: Atributos do retangulo (id, x, y, w, h, cor da borda, cor de preenchimento e [OPCIONAL - utilizado apenas na consulta o? do arquivo 
QRY]: 1 - Cria um retângulo tracejado se as figuras não se sobrepõem e 0 - retângulo normal)
Pós: Retorna o endereço do circulo
*/ 
Retangulo criaRetangulo(int id, float x, float y, float w, float h, char* cb, char* cp, int tracejado);

//Setters
/*
Define algum atributo do retangulo
Pre: Atributo do retangulo referente que deseja-se definir
Pós: Nenhum
*/
void retanguloSetId(Retangulo retangulo, int id);
void retanguloSetX(Retangulo retangulo, float x);
void retanguloSetY(Retangulo retangulo, float y);
void retanguloSetWidth(Retangulo retangulo, float w);
void retanguloSetHeight(Retangulo retangulo, float h);
void retanguloSetCorBorda(Retangulo retangulo, char* cb);
void retanguloSetCorPreenchimento(Retangulo retangulo, char* cp);
void retanguloSetTracejado(Retangulo retangulo, int tracejado);


//Getters
/*
Obtém algum atributo do retangulo
Pre: Retangulo
Pós: Retorna o atributo em questão
*/
int retanguloGetId(Retangulo retangulo);
float retanguloGetX(Retangulo retangulo);
float retanguloGetY(Retangulo retangulo);
float retanguloGetWidth(Retangulo retangulo);
float retanguloGetHeight(Retangulo retangulo);
char* retanguloGetCorBorda(Retangulo retangulo);
char* retanguloGetCorPreenchimento(Retangulo retangulo);
int retanguloGetTracejado(Retangulo retangulo);


#endif