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

void insertAfter(Lista lista, Node node, Info info);
void insertBefore(Lista lista, Node node, Info info);

void removeList(Lista lista);


#endif