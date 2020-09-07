#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct node{
    Info info;
    struct node* prox;
    struct node* ant;
}NodeStruct;

typedef struct lista{
    NodeStruct* primeiro;
    NodeStruct* ultimo; 
}ListaStruct;


Lista create(){
    ListaStruct* lista = (ListaStruct*) malloc(sizeof(ListaStruct));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insert(Lista lista, Info info){
    ListaStruct* lis = (ListaStruct*) lista;
    NodeStruct* node = (NodeStruct*) malloc(sizeof(NodeStruct));
    node->info = info;

    if(lis->primeiro == NULL){
        lis->primeiro = node;
        node->ant = NULL;
        //prox = NULL
    }
    else{
        lis->ultimo->prox = node;
        node->ant = lis->ultimo;
    }
    node->prox = NULL;
    lis->ultimo = node;
}

/*
void print(Lista lista){
    ListaStruct* lis = (ListaStruct*) lista;
    NodeStruct* aux = lis->primeiro;

    while(aux->prox != NULL){
        printf("%d", aux);
        aux = aux->prox;
    }
}
*/

Node getFirst(Lista lista){
    ListaStruct* lis = (ListaStruct*) lista;
    return lis->primeiro;
}

Node getLast(Lista lista){
    ListaStruct* lis = (ListaStruct*) lista;
    return lis->ultimo;
}


Node getNext(Node node){
    NodeStruct* nod = (NodeStruct*) node;
    return nod->prox;
}

Node getPrevious(Node node){
    NodeStruct *nod = (NodeStruct*) node;
    return nod->ant;
}




/*
    insertAfter()
    insertBefore()
    removeNode()
    removeList()
*/




