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
    NodeStruct* nod = (NodeStruct*) malloc(sizeof(NodeStruct));
    nod->info = info;

    if(lis->primeiro == NULL){
        lis->primeiro = nod;
        nod->ant = NULL;
        //prox = NULL
    }
    else{
        lis->ultimo->prox = nod;
        nod->ant = lis->ultimo;
    }
    nod->prox = NULL;
    lis->ultimo = nod;
}


Info getInfo(Node node){
    NodeStruct* nod = (NodeStruct*) node;
    return nod->info;
}

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
    NodeStruct* nod = (NodeStruct*) node;
    return nod->ant;
}


void insertAfter(Lista lista, Node node, Info info){
    ListaStruct* lis = (ListaStruct*) lista;
    NodeStruct* nod = (NodeStruct*) node;

    NodeStruct* novo = (NodeStruct*) malloc(sizeof(NodeStruct));
    novo->info = info;

    if(nod->prox == NULL){
        nod->prox = novo;
        novo->prox = NULL;
        novo->ant = nod;
        lis->ultimo = novo;
    }
    else{
        NodeStruct* aux = nod->prox;
        nod->prox = novo;
        novo->prox = aux;
        novo->ant = nod;
        aux->ant = novo;
    }

}

void insertBefore(Lista lista, Node node, Info info){
    ListaStruct* lis = (ListaStruct*) lista;
    NodeStruct *nod = (NodeStruct*) node;

    NodeStruct* novo = (NodeStruct*) malloc(sizeof(NodeStruct));
    novo->info = info;

    if(nod->ant == NULL){
        nod->ant = novo;
        novo->prox = nod;
        novo->ant = NULL;
        lis->primeiro = novo;
    }
    else{
        NodeStruct* aux = nod->ant;
        nod->ant = novo;
        novo->prox = nod;
        novo->ant = aux;
        aux->prox = novo;
    }
}

void removeNode(Lista lista, Node node){
    ListaStruct* lis = (ListaStruct*) lista;
    NodeStruct* nod = (NodeStruct*) node;

    //Se for o primeiro 
    if(nod->ant == NULL){
        lis->primeiro = nod->prox;
    }
    else{
        nod->ant->prox = nod->prox;
    }

    if(nod->prox == NULL){
        lis->ultimo = nod->ant;
    }
    else{
        nod->prox->ant = nod->ant;
    }

    free(getInfo(nod));
    free(nod);
}

void removeList(Lista lista){
    ListaStruct* lis = (ListaStruct*) lista;
    NodeStruct* inicio = lis->primeiro;

    NodeStruct *aux;
    while(inicio != NULL){
        aux = inicio;
        inicio = inicio->prox;
        free(getInfo(aux));
        free(aux);
    }
    free(lis);
}
