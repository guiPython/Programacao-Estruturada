#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Libs/csv.h"
#include "Libs/matriz.h"

int main(void) {

    // Atribuicao Variaveis/Ponteiros
    int rows, cols, rows2, cols2,rres,cres;
    float **matriz = buildMatriz();
    float **matriz2 = buildMatriz();
    float **res = buildMatriz();
    FILE *file = getArquivo("teste.csv");
    FILE *file2 = getArquivo("teste2.csv");

    // Execucao de Funcoes
    loadMatriz(file, matriz, &rows, &cols);
    printf("Matriz I %d X %d ", rows, cols);
    printf("\n");
    printMatriz(matriz, &rows, &cols);

    printf("\n");
    loadMatriz(file2, matriz2, &rows2, &cols2);
    printf("Matriz II %d X %d ", rows2, cols2);
    printf("\n");
    printMatriz(matriz2, &rows2, &cols2);

    printf("\n");
    printf("Matriz I x Matriz II");
    printf("\n");
    multMatrizes(matriz,&rows,&cols,matriz2,&rows2,&cols2,res,&rres,&cres);
    printMatriz(res,&rres,&cres);

    for (int i = 0; i < MAX_COLS; i++)
    {
        free(matriz[i]);
        free(matriz2[i]);
        free(res[i]);
    }
    free(matriz);
    free(matriz2);
    free(res);

    return 0;
}