#ifndef LINHA__H_
#define LINHA__H_

typedef void* Linha;

/*
Cria uma linha (Existe apenas quando tem-se os comandos no arquivo QRY, i? e del)
Pre: Atributos da linha (x1, y1, x2, y2, [OPCIONAIS: i?:ponto inicial (1 - a linha terá um ponto que mostra a 
coordenada x,y no arquivo SVG e 0 - não terá; del: cep - Mostra o cep ou id da quadra ou equipamento urbano retirado])
Pós: Retorna o endereço da linha
*/
Linha criaLinha(float x1, float y1, float x2, float y2, int pntInicial, int interna, char* cep);

//Setters
/*
Define algum atributo da linha
Pre: Atributo da linha referente que deseja-se definir
Pós: Nenhum
*/
void linhaSetX1(Linha linha, float x1);
void linhaSetY1(Linha linha, float y1);
void linhaSetX2(Linha linha, float x2);
void linhaSetY2(Linha linha, float y2);
void linhaSetPntInicial(Linha linha, int pntInicial);
void linhaSetInterna(Linha linha, int interna);
void linhaSetCep(Linha linha, char* cep);

//Getters
/*
Obtém algum atributo da linha
Pre: Linha
Pós: Retorna o atributo em questão
*/
float linhaGetX1(Linha linha);
float linhaGetY1(Linha linha);
float linhaGetX2(Linha linha);
float linhaGetY2(Linha linha);
int linhaGetPntInicial(Linha linha);
int linhaGetInterna(Linha linha);
char* linhaGetCep(Linha linha);

#endif