#ifndef AVL_H 
#define AVL_H

#define path1 "arquivos/file1.txt"
#define path2 "arquivos/file2.txt"
#define path3 "arquivos/file3.txt"
#define path4 "arquivos/search1.txt"
#define path5 "arquivos/search2.txt"
#define path6 "arquivos/search3.txt"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

typedef struct avRecord avRecord;
typedef struct avTree avTree;

struct avRecord{
	double key;
	double value;
};

struct avTree{
	avRecord reg;
	avTree *esq, *dir;
	int weight;
};

avTree* CreateTree();
void insertTree(avTree **t, avRecord r);
void pesquisa(avTree **t, avTree **aux, avRecord r, int *cont);

void preordem(avTree *t);
void central(avTree *t);
void posordem(avTree *t);

int getWeight(avTree **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(avTree **t);
void rotacaoSimplesEsquerda(avTree **t);
void rotacaoDuplaDireita(avTree **t);
void rotacaoDuplaEsquerda(avTree **t);

void fillAVLTree(char *path, avTree **t);
void searchAVLTree(char *path, avTree **t, avTree **aux, int *cont);

void avlMain();

#endif