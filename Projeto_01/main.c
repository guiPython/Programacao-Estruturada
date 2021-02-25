#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Libs/csv.h"
#include "Libs/matriz.h"

int main(void) {

    Matriz m1 , m2 , res;
    m1.matriz = buildMatriz(); m2.matriz = buildMatriz() ; res.matriz = buildMatriz();
    FILE *file = getArquivo("teste.csv");
    FILE *file2 = getArquivo("teste2.csv");

    // Execucao de Funcoes
    printf("\n");
    loadMatriz(file, &m1);
    printf("Matriz I %d X %d ", m1.rows, m1.cols);
    printf("\n");
    printMatriz(&m1);

    printf("\n");
    loadMatriz(file2, &m2);
    printf("Matriz II %d X %d ", m2.rows, m2.cols);
    printf("\n");
    printMatriz(&m2);

    printf("\n");
    printf("Matriz I x Matriz II");
    printf("\n");
    multMatrizes(&m1,&m2,&res);
    printMatriz(&res);

    printf("\n");
    float num;
    printf("Digite um Escalar: ");
    scanf("%f",&num);
    printf("\n");
    printf("Matriz I x Matriz II + %.2f",num);
    printf("\n");
    opEscalarMatriz(&res,&num,"soma");
    printMatriz(&res);
    printf("\n");
    printf("Matriz I x Matriz II - %.2f",num);
    printf("\n");
    opEscalarMatriz(&res,&num,"subtr");
    printMatriz(&res);
    printf("\n");
    printf("Matriz I x Matriz II x %.2f",num);
    printf("\n");
    opEscalarMatriz(&res,&num,"mult");
    printMatriz(&res);
    printf("\n");
    printf("Matriz I x Matriz II / %.2f",num);
    printf("\n");
    opEscalarMatriz(&res,&num,"divs");
    printMatriz(&res);

    for (int i = 0; i < MAX_COLS; i++)
    {
        free(m1.matriz[i]);
        free(m2.matriz[i]);
        free(res.matriz[i]);
    }
    free(m1.matriz);
    free(m2.matriz);
    free(res.matriz);

    return 0;
}