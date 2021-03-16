#ifndef VETOR
#define VETOR

#include <stdio.h>

typedef struct {
    int dim;
    float* vetor;

}Vetor;

Vetor prepVetor(char* filepath);
void printVetor(Vetor v);
void loadVetor(Vetor* v,FILE* arq);
void allocVetor(Vetor* v);
void clearVetor(Vetor* v);
int eqVetor(Vetor a, Vetor b);
Vetor opeEscVetor(float a, Vetor vetor, char ope);
float prodEscVetor(Vetor a, Vetor b);
Vetor prodVetVetor(Vetor a, Vetor b);
float moduloVetor(Vetor a);
float angVetores(Vetor a, Vetor b);

//#include "vetor.c"
#endif