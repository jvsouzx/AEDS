#ifndef RB_H 
#define RB_H

#define path1 "arquivos/file1.txt"
#define path2 "arquivos/file2.txt"
#define path3 "arquivos/file3.txt"
#define path4 "arquivos/search1.txt"
#define path5 "arquivos/search2.txt"
#define path6 "arquivos/search3.txt"

#define RED 1
#define BLACK 0

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

typedef struct rbRecord rbRecord;
typedef struct rbTree rbTree;

struct rbRecord{
	double key;
	double value;
};

struct rbTree{
	rbRecord reg;
	rbTree *esq, *dir;
    rbTree *parent;
    int color;
};

rbTree* CreateRBTree();
void rbSearch(rbTree **t, rbTree **aux, rbRecord r, int *cont);
void insert(rbTree **t, rbRecord r);
void insertRB(rbTree **t, rbRecord r);
void rightRotate(rbTree **t);
void leftRotate(rbTree **t);

void searchRBTree(char *path, rbTree **t, rbTree **aux, int *cont);
void fillRBTree(char *path, rbTree **t);

void rbPreordem(rbTree *t);
void rbCentral(rbTree *t);
void rbPosordem(rbTree *t);

void rbMain();

#endif