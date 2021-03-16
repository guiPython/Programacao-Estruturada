#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../csv/csv.h"
#include "vetor.h"
#include <math.h>

int NallocVetor = 0, NdeallocVetor = 0;

void allocVetor(Vetor* v) {
    v->vetor = (float*)malloc(v->dim * sizeof(float));
    NallocVetor++;
}


void loadVetor(Vetor* v, FILE* arq) {
    int i = 0;
    char* token;
    char line[4096];
    while (fgets(line, sizeof(line), arq)) {
        for (token = strtok(line, ";"); token ; token = strtok(NULL, ";")) {
            i++;
        }
    }
    v->dim = i;
    allocVetor(v);

    rewind(arq);
    i = 0;
    while (fgets(line, sizeof(line), arq)) {
        for (token = strtok(line, ";"); token ; token = strtok(NULL, ";")) {
            v->vetor[i] = atof(token);
            i++;
        }
    }
    fclose(arq);
}


void clearVetor(Vetor* v) {
    if (v->dim <= 0) return;
    free(v->vetor);
    NdeallocVetor++;
    v->dim = 0;
}

void salvarVetor(Vetor* v, char* fileName)
{
    FILE* file = fopen(fileName, "wb");
    for (int i = 0; i < v->dim; i++)
    {
        if (i == v->dim - 1)
            fprintf(file, "%.3f", v->vetor[i]);
        else
            fprintf(file, "%.3f;", v->vetor[i]);
    }
    fclose(file);
}

Vetor criarVetorMesmoTamanho(Vetor v){
    Vetor u;
    u.dim = v.dim;
    allocVetor(&u);
    return u;
}

Vetor prepVetor(char* filepath){
    Vetor a;
    FILE* arq = getArquivo(filepath);
    loadVetor(&a, arq);
    return a;
}


int eqVetor(Vetor a, Vetor b) {
    if (a.dim != b.dim) { return 0; }
    else {
        for (int i = 0; i < a.dim; i++) {
            if (a.vetor[i] != b.vetor[i]) { return 0; }
        }
        return 1;
    }
}

void printVetor(Vetor v){
    for(int i = 0; i < v.dim; i++){
        printf("%.2f ", v.vetor[i]);
    }
    printf("\n");
}

Vetor opeEscVetor(float a, Vetor v, char ope){
    Vetor u = criarVetorMesmoTamanho(v);
    for(int i = 0; i < v.dim; i++){
        if(ope == '+'){
            u.vetor[i] = v.vetor[i] + a;
        }
        if(ope == '-'){
            u.vetor[i] = v.vetor[i] - a;
        } 
        if(ope == '*'){
            u.vetor[i] = v.vetor[i] * a;
        } 
        if(ope == '/'){
            u.vetor[i] = v.vetor[i] / a;
        } 
    }
    return u;
}

float prodEscVetor(Vetor a, Vetor b){
    if(a.dim == b.dim){
        float c = 0;
        for(int i = 0; i < a.dim; i++){
            c = c + a.vetor[i] * b.vetor[i];
        }
        return c;
    }
    kill("ERRO");
}

float moduloVetor(Vetor a){
    float x = 0, y;
    for(int i = 0; i < a.dim; i++){
        x = x + pow(a.vetor[i], 2);
    }
    y = sqrt(x);
    return y;
}

float angVetores(Vetor a, Vetor b) {
    return prodEscVetor(a, b) / (moduloVetor(a) * moduloVetor(b));
}

Vetor prodVetVetor(Vetor a,Vetor b) {
    if (a.dim == b.dim && a.dim == 3) {
        Vetor n = criarVetorMesmoTamanho(a);
        n.vetor[0] = (a.vetor[1] * b.vetor[2]) - (a.vetor[2] * b.vetor[1]);
        n.vetor[1] = (a.vetor[2] * b.vetor[0]) - (a.vetor[0] * b.vetor[2]);
        n.vetor[2] = (a.vetor[0] * b.vetor[1]) - (a.vetor[1] * b.vetor[0]);
        return n;
    }
    else
    {
        kill("ERRO");
    }
}

Vetor sumVetor(Vetor a, Vetor b)
{
    if (a.dim != b.dim) kill("Erro: Vetores de tamanhos diferentes");
    Vetor u = criarVetorMesmoTamanho(a);
    for (int i = 0; i < a.dim; i++)
    {
        u.vetor[i] = a.vetor[i] + b.vetor[i];
    }
    return u;
}

Vetor subVetor(Vetor a, Vetor b)
{
    if (a.dim != b.dim) kill("Erro: Vetores de tamanhos diferentes");
    Vetor u = criarVetorMesmoTamanho(a);
    for (int i = 0; i < a.dim; i++)
    {
        u.vetor[i] = a.vetor[i] - b.vetor[i];
    }
    return u;
}
