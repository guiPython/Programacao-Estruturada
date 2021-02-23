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


void loadMatriz(FILE* arq, float** matriz, int* row, int* col) {
    int i = 0;
    char* token;
    char line[1024];
    while (fgets(line, sizeof(line), arq)) {
        int j = 0;
        for (token = strtok(line, ";"); token && *token; j++, token = strtok(NULL, ";")) {
            matriz[i][j] = atof(token);
        }
        *col = j;
        i++;
    }
    *row = i;
    fclose(arq);
}


void printMatriz(float** matriz, int* rows, int* cols) {
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void multEscalarMatriz(float** matriz, int* rows ,int* cols , float* esc){
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            matriz[i][j] *= (*esc);
        }
    }
}

void multMatrizes(float**m1,int*r1,int*c1,float**m2,int*r2,int*c2,float**res,int*rres,int*cres){

    if ( *c1 != *r2 ){
        printf("\nNão é realizar a operção, Numero de colunas de M1 != Numero de linhas de M2.");
    }
    else{
        for ( int i = 0 ; i < *c1 ; i++){
            for ( int j = 0; j < *c1; j++){
                res[i][j] = (m1[i][j]) * (m2[j][i]);
            }
        }
        *rres = *r1 ; *cres = *c2;
    }
    
}