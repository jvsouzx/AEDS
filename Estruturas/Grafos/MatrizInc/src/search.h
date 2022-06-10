#ifndef SEARCH_H 
#define SEARCH_H

#include<stdio.h>
#include<stdlib.h>
#include"incMatrix.h"

typedef struct TipoItem Item;
typedef struct TipoFila Fila;

struct TipoItem{
    int data;
  Item *prox;
};

struct TipoFila{
  Item *head;
  Item *tail;
  int size;
};

Fila* FFVazia();
void Queue(Fila *f, int vertex);
Item* Dequeue(Fila *f);

void BFS(Graph G, Vertex s);
void DFS(Graph G);
void DFS_VISIT(Graph G, Vertex *v, int index,int *cor, int *d, int *f, int *tempo);

#endif