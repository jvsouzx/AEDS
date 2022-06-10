#ifndef MEMORIA_H
#define MEMORIA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX 5
#define MAXSWAP 50

int NumProcess(char *path, int numP);
void InitMemory(int numP, int memory[numP][MAX]);
void InitSwap(int numP, int swap[numP][MAXSWAP]);
void ExecProcess(char *path, Lista *p/*, int numP, int memory[numP][MAX], int swap[numP][MAXSWAP]*/);

#endif