#ifndef __LISTA_H
#define __LISTA_H

typedef void* Lista;
typedef void* Node;
typedef void* Info;

/*
Cria uma nova lista
Pré: Nenhum
Pós: Retorna o endereço da lista 
*/
Lista create();

/*
Insere um novo elemento na lista
Pré: A lista e a informação a ser inserida 
Pós: Nenhum
*/
void insert(Lista lista, Info info);

/*
Obtém a informação desejada
Pré: O nó da qual a informação se encontra
Pós: Retorna o endereço da informação
*/
Info getInfo(Node node);

/*
Obtém o primeiro elemento da lista
Pré: A lista 
Pós: Retorna o endereço do primeiro elemento da lista especificada
*/
Node getFirst(Lista lista);

/*
Obtém o último elemento da lista
Pré: A lista 
Pós: Retorna o endereço do último elemento da lista especificada
*/
Node getLast(Lista lista);

/*
Obtém o pŕoximo elemento do nó
Pré: O nó
Pós: Retorna o endereço do próximo elemento do nó especificado
*/
Node getNext(Node node);

/*
Obtém o elemento anterior do nó (elemento)
Pré: O nó
Pós: Retorna o endereço do elemento anterior do nó especificado
*/
Node getPrevious(Node node);

/*
Insere um elemento após o nó especificado
Pré: A lista, o nó e a informação que deseja-se guardar
Pós: Nenhum
*/
void insertAfter(Lista lista, Node node, Info info);

/*
Insere um elemento antes do nó especificado
Pré: A lista, o nó e a informação que deseja-se guardar
Pós: Nenhum
*/
void insertBefore(Lista lista, Node node, Info info);

/*
Deleta um elemento da lista
Pré: A lista da qual o elemento está e o nó em questão
Pós: Nenhum
*/
void removeNode(Lista lista, Node node);

/*
Deleta a lista especificada
Pré: A lista em questão
Pós: Nenhum
*/
void removeList(Lista lista);


#endif