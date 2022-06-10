#ifndef FILE_H
#define FILE_H

#include<time.h>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>

void fileMinMax(char *path, int *min, int *max);
void separa(char *path);
void searchInFile(char *path, int src);

#endif