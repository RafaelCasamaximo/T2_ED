#ifndef QRY__H_
#define QRY__H_

#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"

/*
Muda a cor de uma figura;
Pré: Lista para procurar ID da figura, nova cor de borda, cor de preenchimento, e arquivo para fazer LOG
Pós: Nenhum
*/
void pnt(Lista* listas, int j, char* cb, char* cp, FILE* fileTxt);

/*
Muda a cor de N figuras entre j e k;
Pré: Lista para procurar ID das figuras, nova cor de borda, cor de preenchimento, e arquivo para fazer LOG
Pós: Nenhum
*/
void pntAst(Lista* listas, int j, int k, char* cb, char* cp, FILE* fileTxt);

/*
Deleta um elemento da lista
Pré: Lista e id do elemento
Pós: Nenhum
*/
void delf(Lista* listas, int j);

/*
Deleta N elemento da lista entre j e k
Pré: Lista e id do elemento
Pós: Nenhum
*/
void delfAst(Lista* listas, int j, int k);

/*
Verifica se um ponto é interno ou externo ao circulo;
Pré: coordenadas x e y do ponto, coordenadas x, y, e raio do circulo
Pós: 0 - fora, 1 - dentro
*/
int insideCirculo(float x, float y, float cx, float cy, float r);

/*
Verifica se um ponto é interno ou externo ao retangulo;
Pré: coordenadas x e y do ponto, coordenadas x, y, w e h do retangulo
Pós: 0 - fora, 1 - dentro, 2 - borda
*/
int insideRetangulo(float x, float y, float rx, float ry, float rw, float rh);

/*
Verifica se um ponto é interno ou externo a uma figura;
Pré: listas para procurar J, identificador J, coordenadas x e y do ponto, arquivo para log
Pós: altera centroDeMassaX e centroDeMassaY para desenhar a linha posteriormente ligando o centro da figura com o ponto
*/
int iInt(Lista* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY, FILE* fileTxt);

/*
Verifica se um circulo e um retangulo se sobrepoem;
Pré: Circulo c e Retangulo r
Pós: 0 - não se sobrepõem, 1 - se sobrepõem
*/
int overlayCirculoRetangulo(Circulo c, Retangulo r);

/*
Verifica se um circulo e um circulo se sobrepoem;
Pré: Circulo c1 e Circulo c2
Pós: 0 - não se sobrepõem, 1 - se sobrepõem
*/
int overlayCirculoCirculo(Circulo c1, Circulo c2);

/*
Verifica se um retangulo e um retangulo se sobrepoem;
Pré: Retangulo r1 e Retangulo r2
Pós: 0 - não se sobrepõem, 1 - se sobrepõem
*/
int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2);

/*
Verifica se duas figuras se sobrepõem
Pré: Lista para procurar figuras, identificador J e K das figuras, e arquivo para fazer LOG
Pós: Altera x, y, w, h para desenhar o retangulo cheio ou tracejado posteriormente/ 0 - não se sobrepõem, 1 - se sobrepõem
*/
int oInt(Lista* listas, int j, int k, float* x, float* y, float* w, float* h, FILE* fileTxt);

/*
Deleta uma quadra ou equipamento urbano;
Pré: Lista para encontrar o elemento, cep ou id
Pós: Nenhum
*/
void del(Lista* listas, char* cep);

/*
Muda a cor da borda de todas as quadras que estiverem dentro do raio R centrado em X e Y;
Pré: Lista para procurar elementos, R, X e Y para formar o circulo de efeito, cor da borda para alteração
Pós: Nenhum
*/
void cbq(Lista* listas, float x, float y, float r, char* cb);

/*
Remove/ pinta todas as quadras no raio R de um equipamento urbano identificado pelo id
Pré: Lista para procurar elemento, id identificador, raio, hashtag (valor inteiro que varia entre 1 e 0 para dizer se as quadras serão deletadas ou somente terão suas cores alteradas)
Pós: Nenhum
*/
void dq(Lista* listas, char* id, float r, int hashtag, int identificadorFigura);

/*
Calcula area total das quadras dentro de um retangulo e mostra no svg
Pré: Lista para procurar elemento, x, y, w e h para informar o retangulo, id para gerar novas figuras.
Pós: Nenhum
*/
void car(Lista* listas, float x, float y, float w, float h, int id);

#endif