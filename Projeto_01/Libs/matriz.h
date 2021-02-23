#ifndef MATRIZ
#define MATRIZ

#include <stdio.h>

float** buildMatriz(void);
void loadMatriz(FILE *file, float **matriz, int*rows, int*cols);
void printMatriz(float **matriz, int*rows, int*cols);
void multEscalarMatriz(float **matriz, int*rows, int*cols, float*escalar);
void multMatrizes(float**m1,int*r1,int*c1,float**m2,int*r2,int*c2,float**res,int*rres,int*cres);

#include "matriz.c"
#endif 