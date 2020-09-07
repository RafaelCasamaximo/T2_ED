#ifndef __LISTA_H
#define __LISTA_H

typedef void* Lista;
typedef void* Node;
typedef void* Info;

Lista create();

void insert(Lista lista, Info info);
void print(Lista lista);

Node getFirst(Lista lista);
Node getLast(Lista lista);
Node getNext(Node node);
Node getPrevious(Node node);

/*
    Lista create();
    void insert(Lista l, int info);
    void print(Lista l);
    insertAfter()
    insertBefore()
    getFirst()
    getLast()
    getNext()
    getPrevious()
*/



#endif