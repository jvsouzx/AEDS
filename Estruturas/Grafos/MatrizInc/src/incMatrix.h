#ifndef INCMATRIX_H
#define INCMATRIX_H

#include<stdlib.h>
#include<stdio.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;


struct TipoVertex{
  int value;
  Vertex prox;
};


struct graph{
  int V;
  int E;
  Vertex **matrix;
};

Vertex VertexInitialize(int value);
Graph GraphInitialize(int V);
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2);
void ImprimeGraph(Graph G);

#endif