#include "search.h"

Fila* FFVazia(){
  Fila *f = (Fila*) malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  return f;
}

void Queue(Fila *f, int vertex){
  Item *d = (Item *) malloc (sizeof(Item));
  d->data = vertex;
  d->prox = NULL;

  if(f->head == NULL){
    f->head = d;
    f->tail = d;
  }else{
    f->tail->prox = d;
    f->tail = d;
  }

  f->size ++;
}

Item* Dequeue(Fila *f){
  Item *aux;

  if(f->head == NULL)
    return NULL;

  aux = f->head;
  f->head = f->head->prox;
  f->size --;

  return aux;
}

void BFS(Graph G, Vertex s){
  int cor[G->V]; //0 Branco, 1 Cinza, 2 Preto
  int d[G->V];
  int pi[G->V]; 
  Fila *f = FFVazia();

  for(int i=0; i<G->V; i++)
    if(i != s->value){
      cor[i] = 0;
      d[i]   = -1; 
      pi[i]  = -1; 
    }

  cor[s->value] = 1;
  d[s->value]   = 0;
  pi[s->value]  = -1;

  Queue(f, s->value);

  while (f->size > 0) {
    Item *u = Dequeue(f);
    for (int v = 0; v < G->V; v++) {
      if (G->matrix[u->data][v]->value == 1 && cor[v] == 0) {
        cor[v] = 1;
        d[v] = d[u->data] + 1;
        pi[v] = u->data;
        Queue(f, v);
      }
    }
    cor[u->data] = 2;
    printf("Vertex:%3d\n", u->data);
  }
}

void DFS_VISIT(Graph G, Vertex *v, int index,int *cor, int *d, int *f, int *tempo){
   cor[index] = 1;
  *tempo += 1;
  d[index] = *tempo;
  for (int u = 0; u < G->V; u++) {
    if (v[u]->value == 1 && cor[u] == 0) {
      DFS_VISIT(G, G->matrix[u], u, cor, d, f, tempo);
    }
  }
  cor[index] = 2;
  *tempo += 1;
  f[index] = *tempo;
  printf("Vertex:%3d  |  D:%3d  |  F:%3d\n", index, d[index], f[index]);
}

void DFS(Graph G){
  int cor[G->V]; // Branco 0, Cinza 1, Preto 2
  int d[G->V];   
  int f[G->V];   
  int tempo = 0;

  for(int v=0; v<G->V; v++)
    cor[v] = 0;

  for(int v=0; v<G->V; v++)
    if(cor[v] == 0)
      DFS_VISIT(G, G->matrix[v], v, cor, d, f, &tempo);
}