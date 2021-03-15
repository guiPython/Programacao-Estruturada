#ifndef MATRIZ
#define MATRIZ
#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    float** matriz;
} Matriz;


void kill(const char* erro);
static void allocMatriz(Matriz* m);
static void loadMatriz(Matriz *m, FILE *file);
Matriz prepMatriz(char*);
matriz copiarMatriz(Matriz* src);
Matriz criarMatrizDeMesmoTamanho(Matriz* src);
Matriz criarMatrizDeTamanho(int rows,int cols);
Matriz criarMatrizIdentidade(int n);
void clearMatriz(Matriz *m);
int  eqMatriz(Matriz*,Matriz*);
void printMatriz(Matriz *m);
void opEscalarMatriz(Matriz *m, float *num, char op);
void sumMatrizes(Matriz *m1, Matriz *m2, Matriz *res);
void subtrMatrizes(Matriz *m1, Matriz *m2, Matriz *res);
void multMatrizes(Matriz *m1, Matriz *m2, Matriz *res);
float detMatriz(Matriz m);
float detMatrizSarrus(Matriz m);
float detMatrizLaplace(Matriz m);

#include "matriz.c"
#endif 