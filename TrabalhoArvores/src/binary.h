#ifndef BINARY_H 
#define BINARY_H

#define path1 "arquivos/file1.txt"
#define path2 "arquivos/file2.txt"
#define path3 "arquivos/file3.txt"
#define path4 "arquivos/search1.txt"
#define path5 "arquivos/search2.txt"
#define path6 "arquivos/search3.txt"

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include<stdbool.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	double key;
	double value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateBTree();
void insertBTree(Tree **t, Record r);
void binarySearch(Tree **t, Tree **aux, Record r, int *cont);

void binaryPreordem(Tree *t);
void binaryCentral(Tree *t);
void binaryPosordem(Tree *t);

void searchBTree(char *path, Tree **t, Tree **aux, int *cont);
void fillBTree(char *path, Tree **t);
void binaryMain();

#endif