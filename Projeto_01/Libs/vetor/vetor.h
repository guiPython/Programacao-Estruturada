#ifndef VETOR
#define VETOR

#include <stdio.h>

typedef struct {
    int dim;
    float* vetor;

}Vetor;

Vetor carregaVetor(char* filepath);
void kill(const char* erro);
void printVetor(Vetor v);
void loadVetor(Vetor* v,FILE* arq);
void allocVetor(Vetor* v);
void opeEscVetor(float a, Vetor* vetor, char ope);
float prodEscVetor(Vetor a, Vetor b);
float moduloVetor(Vetor a);

//#include "vetor.c"
#endif