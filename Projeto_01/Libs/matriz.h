#ifndef MATRIZ
#define MATRIZ

#include <stdio.h>

int** buildMatriz(void);
void readMatriz(FILE *file, int **matriz, int*rows, int*cols);
void printMatriz(int **matriz, int*rows, int*cols);

#include "matriz.c"
#endif 