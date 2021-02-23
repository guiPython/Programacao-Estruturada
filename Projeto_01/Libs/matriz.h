#ifndef MATRIZ
#define MATRIZ

#include <stdio.h>

float** buildMatriz(void);
void readMatriz(FILE *file, float **matriz, int*rows, int*cols);
void printMatriz(float **matriz, int*rows, int*cols);
void multEscalarMatriz(float **matriz, int*rows , int*cols , float*esc);

#include "matriz.c"
#endif 