#include "Libs/csv.h"
#include "Libs/matriz.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {

    // Atribuicao Variaveis/Ponteiros
    int rows, cols;
    float esc;
    float **matriz = buildMatriz();
    FILE *file = getArquivo("teste.csv");

    // Execucao de Funcoes
    readMatriz(file, matriz, &rows, &cols);
    printf("Matriz %d X %d ", rows, cols);
    printf("\n");
    printMatriz(matriz, &rows, &cols);



    for ( int i = 0; i <= MAX_COLS; i++ ){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}