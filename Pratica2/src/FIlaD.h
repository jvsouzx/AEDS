#ifndef FILAD_H
#define FILAD_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Itemf Itemf;
typedef struct Blockf Blockf;
typedef struct FilaD FilaD;

typedef struct Itemfb Itemfb;
typedef struct Blockfb Blockfb;
typedef struct FilaDb FilaDb;

typedef struct ItemR ItemR;
typedef struct BlockR BlockR;
typedef struct FilaDR FilaDR;

struct Itemf{
	int k;
    char x;
    char y;
};

struct Blockf{
	Itemf data;
	Blockf *prox;
};

struct FilaD{
	Blockf *first;
	Blockf *last;
};

struct Itemfb{
	int val;
	int peso[5];
};

struct Blockfb{
	Itemfb data;
	Blockfb *prox;
};

struct FilaDb{
	Blockfb *first;
	Blockfb *last;
};

struct ItemR{
	char *result;
};

struct BlockR{
	ItemR data;
	BlockR *prox;
};

struct FilaDR{
	BlockR *first;
	BlockR *last;
};

void FilaBVazia(FilaDb *f);
void EnfileiraB(FilaDb *f, Itemfb d);
void FilaBImprime(FilaDb *f);

void FilaResVazia(FilaDR *f);
void EnfileiraRes(FilaDR *f, ItemR d);
void FilaResImprime(FilaDR *f);

void FilaDVazia(FilaD *f);
void Enfileira(FilaD *f, Itemf d);
void Desenfileira(FilaD *f, Itemf *d);
void FilaDImprime(FilaD *f);

#endif