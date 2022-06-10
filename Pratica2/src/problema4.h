#ifndef PROBLEMA4_H
#define PROBLEMA4_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Itemcl Itemcl;
typedef struct Blockcl Blockcl;
typedef struct Listacl Listacl;

typedef struct Itempp Itempp;
typedef struct Blockpp Blockpp;
typedef struct Pilhapp Pilhapp;

typedef struct Itemff Itemff;
typedef struct Blockff Blockff;
typedef struct Filaff Filaff;


struct Itemcl{
	char *client;
    int id;
    int *carrinho;
};

struct Blockcl{
	Itemcl data;
	Blockcl *prox;
};

struct Listacl{
	Blockcl *first;
	Blockcl *last;
};

struct Itempp{
    char *produto;
	int id;
    float val;
};

struct Blockpp{
	Itempp data;
	Blockpp *prox;
};

struct Pilhapp{
	Blockpp *base;
	Blockpp *top;
};

struct Itemff{
	char *cliente;
};

struct Blockff{
	Itemff data;
	Blockff *prox;
};

struct Filaff{
	Blockff *first;
	Blockff *last;
};

void EmptyClient(Listacl *l);
void ClientInsert(Listacl *l, Itemcl d);
void ClientPrint(Listacl *l);
void CLRemove(Listacl *l, Itemcl d);

void EmptyProd(Pilhapp *p);
void PushProd(Pilhapp *p, Itempp d);
void PopProd(Pilhapp *p, Itempp *d);
void ProdImprime(Pilhapp *p);

void FilaFVazia(Filaff *f);
void EnfileiraF(Filaff *f, Itemff d);
void DesenfileiraF(Filaff *f, Itemff *d);
void FFImprime(Filaff *f);

void problema4();

#endif