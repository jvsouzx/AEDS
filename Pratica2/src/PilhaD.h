#ifndef PILHAD_H
#define PILHAD_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Itempd Itempd;
typedef struct Blockpd Blockpd;
typedef struct PilhaD PilhaD;

struct Itempd{
	int val;
};

struct Blockpd{
	Itempd data;
	Blockpd *prox;
};

struct PilhaD{
	Blockpd *base;
	Blockpd *top;
};

void PilhaDVazia(PilhaD *p);
void DPush(PilhaD *p, Itempd d);
void DPop(PilhaD *p, Itempd *d);
void PilhaDImprime(PilhaD *p);

#endif