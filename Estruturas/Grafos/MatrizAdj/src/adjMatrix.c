#include "adjMatrix.h"

Vertex VertexInitialize(int value) {
  Vertex v = malloc(sizeof(Vertex));
  v->value = value;
  return v;
}

Graph GraphInitialize(int V) {
  Graph G = malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->matrix = (Vertex **)malloc(V * sizeof(Vertex *));
  for (int i = 0; i < V; i++) {
    G->matrix[i] = (Vertex *)malloc(V * sizeof(Vertex));
    for (int j = 0; j < V; j++) {
      G->matrix[i][j] = VertexInitialize(0);
    }
  }
  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2) {
  if (G->matrix[v1->value][v2->value]->value == 1) {
    return;
  }
  G->matrix[v1->value][v2->value]->value = 1;
  G->E++;
}

void ImprimeGraph(Graph G) {
  printf("       ");
  for (int j = 0; j < G->V; j++) {
    printf("[%2d]", j);
  }
  printf("\n");
  printf("       ");
  for (int j = 0; j < G->V; j++) {
    printf(" |  ");
  }
  printf("\n");
  printf("       ");
  for (int j = 0; j < G->V; j++) {
    printf(" V  ");
  }
  printf("\n");
  for (int i = 0; i < G->V; i++) {
    printf("[%2d]-> ", i);
    for (int j = 0; j < G->V; j++) {
      if (G->matrix[i][j]->value == 1) {
        printf("[ 1]");
      } else if (G->matrix[i][j]->value == -1) {
        printf("[-1]");
      } else {
        printf("[  ]");
      }
    }
    printf("\n");
  }
}