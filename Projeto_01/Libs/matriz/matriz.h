#ifndef MATRIZ
#define MATRIZ
#define MAX_COLS 15
#define MAX_ROWS 15

#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    float** matriz;
} Matriz;


static float** buildMatriz(void);
static void loadMatriz(FILE *file, Matriz *m);
Matriz prepMatriz(char*);
void clearMatriz(Matriz *m);
int  eqMatriz(Matriz*,Matriz*);
void printMatriz(Matriz *m);
void opEscalarMatriz(Matriz *m, float *num, char op);
void multMatrizes(Matriz *m1, Matriz *m2, Matriz *res);
float detMatriz(Matriz *m);

#include "matriz.c"
#endif 