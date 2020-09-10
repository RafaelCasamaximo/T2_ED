#ifndef __TEXTO_H
#define __TEXTO_H

typedef void* Texto;

/*
Cria um texto
Pre: Atributos do texto (id, x, y, cor da borda, cor de preenchimento, texto e o tamanho do texto)
Pós: Retorna o endereço do texto
*/ 
Texto criaTexto(int id, float x, float y, char* cb, char* cp, char* txt, int size);

//Setters
/*
Define algum atributo do texto
Pre: Atributo do texto referente que deseja-se definir
Pós: Nenhum
*/
void textoSetId(Texto texto, int id);
void textoSetX(Texto texto, float x);
void textoSetY(Texto texto, float y);
void textoSetCorBorda(Texto texto, char* cb);
void textoSetCorPreenchimento(Texto texto, char* cp);
void textoSetTexto(Texto texto, char* txt, int size);

//Getters
/*
Obtém algum atributo do texto
Pre: Texto
Pós: Retorna o atributo em questão
*/
int textoGetId(Texto texto);
float textoGetX(Texto texto);
float textoGetY(Texto texto);
char* textoGetCorBorda(Texto texto);
char* textoGetCorPreenchimento(Texto texto);
char* textoGetTexto(Texto texto);

/*
Deleta o texto 
Pré: Texto
Pós: Nenhum
*/
void textoDeletaTexto(Texto texto);


#endif