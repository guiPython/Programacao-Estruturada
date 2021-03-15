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
Matriz copiarMatriz(Matriz* src);
Matriz criarMatrizDeMesmoTamanho(Matriz* src);
Matriz criarMatrizDeTamanho(int rows,int cols);
Matriz criarMatrizIdentidade(int n);
void clearMatriz(Matriz *m);
int  eqMatriz(Matriz*,Matriz*);
void printMatriz(Matriz *m);
Matriz opEscalarMatriz(Matriz *m, float num, char op);
Matriz sumMatrizes(Matriz m1, Matriz m2);
Matriz subtrMatrizes(Matriz m1, Matriz m2);
Matriz multMatrizes(Matriz m1, Matriz m2);
float detMatrizLaplace(Matriz m);


#endif 