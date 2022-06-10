#ifndef PROBLEMA3_H
#define PROBLEMA3_H

#include <stdio.h>
#include <stdlib.h>
#include "FilaD.h"
#include <string.h>
#include <time.h>

int fat(int n);
int combinacao(int n, int p);
void Binomio(int n, char x, char y, FilaDR *res);
void FindClasse(FilaDb *f, Itemfb *d);
void FilaMain();

#endif