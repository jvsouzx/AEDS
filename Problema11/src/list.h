#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Item{
	int ind;
	int val[11];
	int proc[50];
}Item;

typedef struct Lista{
	Item vet[1000];
	int first;
	int last;
}Lista;

void ListMake(Lista *l);
void ListInsert(Lista *l, Item d);
void ListRemove(Lista *l, Item d);
void Swap(Item *a, Item *b);
void ListPrint(Lista *l);
void procPrint(Lista *l);

#endif