#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_COLS 15
#define MAX_ROWS 15


float** buildMatriz() {
    float** matriz;
    matriz = (float**)malloc(MAX_ROWS * sizeof(float));
    for (int i = 0; i < MAX_ROWS; ++i) {
        matriz[i] = (float*)malloc(MAX_COLS * sizeof(float));
    }
    return matriz;
}


void loadMatriz(FILE* arq, Matriz *m) {
    int i = 0;
    char* token;
    char line[1024];
    while (fgets(line, sizeof(line), arq)) {
        int j = 0;
        for (token = strtok(line, ";"); token && *token; j++, token = strtok(NULL, ";")) {
            (*m).matriz[i][j] = atof(token);
        }
        (*m).cols = j;
        i++;
    }
    (*m).rows = i;
    fclose(arq);
}


void printMatriz(Matriz *m) {
    for (int i = 0; i < (*m).rows; i++) {
        for (int j = 0; j < (*m).cols; j++) {
            printf("%.2f\t", (*m).matriz[i][j]);
        }
        printf("\n");
    }
}

void multEscalarMatriz(Matriz *m,float *num){
    for (int i = 0; i < (*m).rows; i++) {
        for (int j = 0; j < (*m).cols; j++) {
            (*m).matriz[i][j] *= (*num);
        }
    }
}

void multMatrizes(Matriz *m1, Matriz *m2, Matriz *res){

    if ( (*m1).cols != (*m2).rows ){
        printf("\nNão é realizar a operção, Numero de colunas de M1 != Numero de linhas de M2.");
    }
    else{
        for ( int i = 0 ; i < (*m1).cols ; i++){
            for ( int j = 0; j < (*m1).cols; j++){
                (*res).matriz[i][j] = (*m1).matriz[i][j] * (*m2).matriz[j][i];
            }
        }
        (*res).rows = (*m1).rows ; (*res).cols = (*m2).cols;
    }
    
}