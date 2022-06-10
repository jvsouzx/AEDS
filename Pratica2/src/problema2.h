#ifndef PROBLEMA2_H
#define PROBLEMA2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"Pilha.h"
#include"PilhaD.h"

void Verify(char *str, Pilha *p1);
void Transfer(PilhaD *P1, PilhaD *P2);
void Totient(PilhaD *p);
void PilhaMain();

#endif