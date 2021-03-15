#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../csv/csv.h"
#include "./Vetor.h"
#include <math.h>

void kill(const char* erro)
{
    printf("%s", erro); 
    exit(0);
}

void allocVetor(Vetor* v) {
    v->vetor = (float*)malloc(v->dim * sizeof(float));
}


void loadVetor(Vetor* v, FILE* arq) {
    int i = 0;
    char* token;
    char line[4096];
    while (fgets(line, sizeof(line), arq)) {
        for (token = strtok(line, ";"); token && token; token = strtok(NULL, ";")) {
            i++;
        }
    }
    v->dim = i;
    allocVetor(v);

    rewind(arq);
    i = 0;
    while (fgets(line, sizeof(line), arq)) {
        for (token = strtok(line, ";"); token && token; token = strtok(NULL, ";")) {
            v->vetor[i] = atof(token);
            i++;
        }
    }
    fclose(arq);
}


Vetor carregaVetor(char* filepath){
    Vetor a;
    FILE* arq = getArquivo(filepath);
    loadVetor(&a, arq);
    return a;
}


void printVetor(Vetor v){
    for(int i = 0; i < v.dim; i++){
        printf("%.2f ", v.vetor[i]);
    }
}

void opeEscVetor(float a, Vetor* v, char ope){
    for(int i = 0; i < v->dim; i++){
        if(ope == '+'){
            v->vetor[i] = v->vetor[i] + a;
        }
        if(ope == '-'){
            v->vetor[i] = v->vetor[i] - a;
        } 
        if(ope == '*'){
            v->vetor[i] = v->vetor[i] * a;
        } 
        if(ope == '/'){
            v->vetor[i] = v->vetor[i] / a;
        } 
    }
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