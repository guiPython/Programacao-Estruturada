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


void readMatriz(FILE* arq, float** matriz, int* row, int* col) {
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


void multEscalarMatriz(float** matriz , int* rows , int* cols , float*esc){
    for ( int i = 0 ; i < *rows ; i++){
        for ( int j = 0 ; j < *cols ; j++){
            matriz[i][j] *= (*esc);
        }
    }
}