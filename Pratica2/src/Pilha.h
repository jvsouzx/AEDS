#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#define MAXTAMP 10

typedef struct Itemp{
	char val;
}Itemp;

typedef struct Pilha{
	Itemp vet[MAXTAMP];
	int top;
	int base;
}Pilha;

void PilhaVazia(Pilha *p);
void PUSH(Pilha *p, Itemp d);
void POP(Pilha *p, Itemp *d);
void PilhaImprime(Pilha *p);

#endif