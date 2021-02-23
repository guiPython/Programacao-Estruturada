#ifndef MATRIZ
#define MATRIZ

#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    float** matriz;
} Matriz;


float** buildMatriz(void);
void loadMatriz(FILE *file, Matriz *m);
void printMatriz(Matriz *m);
void multEscalarMatriz(Matriz *m, float *num);
void multMatrizes(Matriz *m1, Matriz *m2, Matriz *res);

#include "matriz.c"
#endif 