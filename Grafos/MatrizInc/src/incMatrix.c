#include "incMatrix.h"

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
  for (int i = 0; i < G->V; i++) {
    G->matrix[i] = (Vertex *)malloc(G->E * sizeof(Vertex));
    for (int j = 0; j < 1; j++) {
      G->matrix[i][j] = VertexInitialize(0);
    }
  }
  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2) {
  G->E++;
  for (int i = 0; i < G->V; i++) {
    G->matrix[i] =
        (Vertex *)realloc(G->matrix[i], G->E * sizeof(Vertex));
    if (i == v1->value) {
      G->matrix[i][G->E - 1] = VertexInitialize(1);
    } else if (i == v2->value) {
      G->matrix[i][G->E - 1] = VertexInitialize(-1);
    } else {
      G->matrix[i][G->E - 1] = VertexInitialize(0);
    }
  }
}

void ImprimeGraph(Graph G) {
  printf("       ");
  for (int j = 0; j < G->E; j++) {
    printf("[%2d]", j);
  }
  printf("\n");
  printf("       ");
  for (int j = 0; j < G->E; j++) {
    printf(" |  ");
  }
  printf("\n");
  printf("       ");
  for (int j = 0; j < G->E; j++) {
    printf(" V  ");
  }
  printf("\n");
  for (int i = 0; i < G->V; i++) {
    printf("[%2d]-> ", i);
    for (int j = 0; j < G->E; j++) {
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