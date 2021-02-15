#include "Libs/csv.h"
#include "Libs/matriz.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {

    // Atribui��o Variaveis/Ponteiros
    int rows, cols;
    int **matriz = buildMatriz();
    FILE *file = getArquivo("teste.csv");

    // Execu��o de Fun��es
    readMatriz(file, matriz, &rows, &cols);
    printf("O arquivo csv tem %d linhas e %d colunas", rows, cols);
    printf("\n");
    printMatriz(matriz, &rows, &cols);
    return 0;
}