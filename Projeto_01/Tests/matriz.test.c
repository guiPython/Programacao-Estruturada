#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/csv/csv.h"
#include "../Libs/matriz/matriz.h"
#include "../Libs/minUnit/minUnit.h"

int tests_run = 0;

Matriz prepMatriz(char *filePath){
    Matriz m; m.matriz = buildMatriz();
    FILE *file = getArquivo(filePath);
    loadMatriz(file,&m);
    return m;
}

void clearMatriz(Matriz m){
    for( int i = 0 ; i < MAX_COLS ; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
}

int eqMatriz(Matriz m1,Matriz m2){
    if (m1.rows != m2.rows || m1.cols != m2.cols) { return 0;}
    else {
        for ( int i = 0 ; i < m1.rows ; i++){
            for ( int j = 0 ; j < m1.cols ; j++){
                if( m1.matriz[i][j] != m2.matriz[i][j] ){ break ; return 0;}
            }
        }
        return 1;
    }
}

static char* SOMA_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/soma.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'+');
    mu_assert("ERROR: FALHA NA SOMA DE ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(m,res));
    clearMatriz(m);
    clearMatriz(res);
    return 0;
}

static char* SUBTRACAO_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/subtr.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'-');
    mu_assert("ERROR: FALHA NA SOMA DE ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(m,res));
    clearMatriz(m);
    clearMatriz(res);
    return 0;
}


static char* MULTIPLICACAO_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/mult.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'*');
    mu_assert("ERROR: FALHA NA SOMA DE ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(m,res));
    clearMatriz(m);
    clearMatriz(res);
    return 0;
}

static char* DIVISAO_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/divs.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'/');
    mu_assert("ERROR: FALHA NA SOMA DE ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(m,res));
    clearMatriz(m);
    clearMatriz(res);
    return 0;
}

static char* all_tests(){
    mu_run_test(SOMA_ESCALAR_MATRIZ);
    mu_run_test(SUBTRACAO_ESCALAR_MATRIZ);
    mu_run_test(MULTIPLICACAO_ESCALAR_MATRIZ);
    mu_run_test(DIVISAO_ESCALAR_MATRIZ);
    return 0;
}

int main(int argc, char **argv){
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}