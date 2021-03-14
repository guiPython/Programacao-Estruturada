#ifndef MATRIZ
#define MATRIZ

#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    float** matriz;
} Matriz;

/** Criação de matriz */
static void kill(const char* erro);
static void allocMatriz(Matriz* m);
static void loadMatriz(Matriz* m, FILE* file);

Matriz carregarMatriz(char* filePath);
Matriz copiarMatriz(Matriz* src);
Matriz criarMatrizDeMesmoTamanho(Matriz* src);
Matriz criarMatrizDeTamanho(int rows, int cols);
Matriz criarMatrizIdentidade(int n);
void clearMatriz(Matriz* m);
void printMatriz(Matriz* m);

/** Operações com matriz */
static void reduzirMatriz(Matriz* m, int a, int b, float fator);
static void trocarLinhas(Matriz* m, int l1, int l2);
static void multLinha(Matriz* m, int l, float val);

int eqMatriz(Matriz* m1, Matriz* m2);
Matriz opEscalarMatriz(Matriz* m, float num, char op);
Matriz sumMatrizes(Matriz* m1, Matriz* m2);
Matriz subtrMatrizes(Matriz* m1, Matriz* m2);
Matriz multMatrizes(Matriz* m1, Matriz* m2);
Matriz inversaMatriz(Matriz* m);
float detMatriz(Matriz* m);
float detMatrizSarrus(Matriz m);
float detMatrizLaplace(Matriz m);

#endif 