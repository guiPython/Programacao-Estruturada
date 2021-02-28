#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../csv/csv.h"
#include "./matriz.h"


static float** buildMatriz() {
    float** matriz;
    matriz = (float**)malloc(MAX_ROWS * sizeof(float));
    for (int i = 0; i < MAX_ROWS; ++i) {
        matriz[i] = (float*)malloc(MAX_COLS * sizeof(float));
    }
    return matriz;
}


static void loadMatriz(FILE* arq, Matriz *m) {
    int i = 0;
    char* token;
    char line[1024];
    while (fgets(line, sizeof(line), arq)) {
        int j = 0;
        for (token = strtok(line, ";"); token && *token; j++, token = strtok(NULL, ";")) {
            (*m).matriz[i][j] = atof(token);
        }
        m->cols = j;
        i++;
    }
    m->rows = i;
    fclose(arq);
}

Matriz prepMatriz(char *filePath){
    Matriz m; m.matriz = buildMatriz();
    FILE *file = getArquivo(filePath);
    loadMatriz(file,&m);
    return m;
}

void clearMatriz(Matriz *m){
    for( int i = 0 ; i < MAX_COLS ; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

int eqMatriz(Matriz *m1,Matriz *m2){
    if (m1->rows != m2->rows || m1->cols != m2->cols) { return 0;}
    else {
        for ( int i = 0 ; i < m1->rows ; i++){
            for ( int j = 0 ; j < m1->cols ; j++){
                if( m1->matriz[i][j] != m2->matriz[i][j] ){ break ; return 0;}
            }
        }
        return 1;
    }
}

void printMatriz(Matriz *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f\t", m->matriz[i][j]);
        }
        printf("\n");
    }
}

void opEscalarMatriz(Matriz *m,float *num,char op){
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if( op == '*' ){ m->matriz[i][j] *= (*num); }
            else if ( op == '+'  ){ m->matriz[i][j] += (*num); }
            else if ( op == '-' ){ m->matriz[i][j] -= (*num); }
            else if ( op == '/'  ){ m->matriz[i][j] /= (*num); }
            else printf("Operecao nao definida.");
        }
    }
}

void multMatrizes(Matriz *m1, Matriz *m2, Matriz *res){
    if ( m1->cols != m2->rows ){
        printf("\nNão é realizar a operção, Numero de colunas de M1 != Numero de linhas de M2.");
    }
    else{
        float val;
        for ( int i = 0 ; i < m1->rows ; i++){
            for ( int j = 0; j < m2->cols; j++){
                val = 0;
                for ( int k = 0 ; k < (*m1).cols ; k++) val += (m1->matriz[i][k]) * (m2->matriz[k][j]);
                (*res).matriz[i][j] = val;
            }
        }
        res->rows = m1->rows ; res->cols = m2->cols;
    }
    
}


float detMatrizLaplace( Matriz *m){
    if ( m->cols == 1){
        return m->matriz[1][1];
    }
    else{

    }
}