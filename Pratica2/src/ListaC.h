#ifndef LISTAC_H
#define LISTAC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Item1 Item1;
typedef struct Block1 Block1;
typedef struct Lista1 Lista1;

typedef struct Item2 Item2;
typedef struct Block2 Block2;
typedef struct Lista2 Lista2;

typedef struct Item3 Item3;
typedef struct Block3 Block3;
typedef struct Lista3 Lista3;

struct Item1{
	char *prd;
    int qtd;
    int id;
};

struct Item2{
	char *mercado;
    int idm;
};

struct Item3{
    int pxm[2];
	float valor;
};

struct Block1{
	Item1 data;
	Block1 *prox;
};

struct Block2{
	Item2 data;
	Block2 *prox;
};

struct Block3{
	Item3 data;
	Block3 *prox;
};

struct Lista1{
	Block1 *first;
	Block1 *last;
};

struct Lista2{
	Block2 *first;
	Block2 *last;
};

struct Lista3{
	Block3 *first;
	Block3 *last;
};

void EmptyListC(Lista1 *l1, Lista2 *l2, Lista3 *l3);
void List1Print(Lista1 *l1);
void List2Print(Lista2 *l2);
void List3Print(Lista3 *l3);
void ListC1Insert(Lista1 *l1, Item1 d1);
void ListC2Insert(Lista2 *l2, Item2 d2);
void ListC3Insert(Lista3 *l3, Item3 d3);
void List1Search(Lista1 *l1, Item1 *d1);
void List2Search(Lista2 *l2, Item2 *d2);

#endif