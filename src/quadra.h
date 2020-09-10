#ifndef __QUADRA_H
#define __QUADRA_H

typedef void* Quadra;

/*
Cria uma quadra
Pre: Atributos da quadra (cep, x, y, w, h, cor da borda, cor de preenchimento e [OPCIONAL - utilizado apenas na consulta dq do 
arquivo QRY: 1 - as quadras removidas terão cantos arredondados, 0 - não terão cantos arrendodados])
Pós: Retorna o endereço da quadra
*/ 
Quadra criaQuadra(char* cep, float x, float y, float w, float h, char* cb, char* cp, int arredondado);

//Setters
/*
Define algum atributo da quadra
Pre: Atributo da quadra referente que deseja-se definir
Pós: Nenhum
*/
void quadraSetCep(Quadra quadra, char* cep);
void quadraSetX(Quadra quadra, float x);
void quadraSetY(Quadra quadra, float y);
void quadraSetWidth(Quadra quadra, float w);
void quadraSetHeight(Quadra quadra, float h);
void quadraSetCorBorda(Quadra quadra, char* cb);
void quadraSetCorPreenchimento(Quadra quadra, char* cp);
void quadraSetArredondado(Quadra quadra, int arredondado);

//Getters
/*
Obtém algum atributo da quadra
Pre:Quadra
Pós: Retorna o atributo em questão
*/
char* quadraGetCep(Quadra quadra);
float quadraGetX(Quadra quadra);
float quadraGetY(Quadra quadra);
float quadraGetWidth(Quadra quadra);
float quadraGetHeight(Quadra quadra);
char* quadraGetCorBorda(Quadra quadra);
char* quadraGetCorPreenchimento(Quadra quadra);
int quadraGetArredondado(Quadra quadra);
float quadraGetArea(Quadra quadra);

#endif