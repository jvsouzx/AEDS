#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
#define MAXTAM 100
#define MAXTAMB 3

typedef struct Item{
	int val;
}Item;

typedef struct Lista{
    Item vet[100];
    int first;
    int last;
}Lista;

typedef struct Listab{
    Item vet[3];
    int first;
    int last;
}Listab;

void EmptyList(Lista *l);
void PrintList(Lista *l);
void ListInsert(Lista *l, Item d);
void Swap(Item *a, Item *b);
void ListBRemove(Listab *l);
void ListBInsert(Listab *l, Item d);
void EmptyListB(Listab *l);
void PrintListB(Listab *l1, Listab *l2); 
void ListB(Listab *l1, Listab *l2);

#endif