#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/matriz/matriz.h"
#include "../Libs/minUnit/minUnit.h"

int tests_run = 0;

static char* SOMA_ESCALAR_MATRIZ() {
    Matriz m = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz res = carregarMatriz("Tests/src/Resultados/soma.csv");
    float num = 2.0F;
    Matriz t = opEscalarMatriz(&m, num, '+');
    mu_assert("ERROR: FALHA NA SOMA DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&t, &res));
    clearMatriz(&m); clearMatriz(&res);
    return 0;
}

static char* SUBTRACAO_ESCALAR_MATRIZ() {
    Matriz m = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz res = carregarMatriz("Tests/src/Resultados/subtr.csv");
    float num = 2.0F;
    Matriz t = opEscalarMatriz(&m, num, '-');
    mu_assert("ERROR: FALHA NA SUBTRACAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&t, &res));
    clearMatriz(&m); clearMatriz(&res);
    return 0;
}

static char* MULTIPLICACAO_ESCALAR_MATRIZ() {
    Matriz m = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz res = carregarMatriz("Tests/src/Resultados/mult.csv");
    float num = 2.0F;
    Matriz t = opEscalarMatriz(&m, num, '*');
    mu_assert("ERROR: FALHA NA MULTIPLICACAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&t, &res));
    clearMatriz(&m); clearMatriz(&res);
    return 0;
}

static char* DIVISAO_ESCALAR_MATRIZ() {
    Matriz m = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz res = carregarMatriz("Tests/src/Resultados/divs.csv");
    float num = 2.0F;
    Matriz t = opEscalarMatriz(&m, num, '/');
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&t, &res));
    clearMatriz(&m); clearMatriz(&res);
    return 0;
}

static char* ADICAO_MATRIZES() {
    Matriz m1 = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz m2 = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz res = carregarMatriz("Tests/src/Resultados/mult.csv");
    Matriz t = sumMatrizes(&m1, &m2);
    mu_assert("ERROR: FALHA NA OPERACAO DE SOMA DE MATRIZES", eqMatriz(&t, &res));
    clearMatriz(&m1); clearMatriz(&m2); clearMatriz(&res);
    return 0;
}

static char* SUBTRACAO_MATRIZES() {
    Matriz m1 = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz m2 = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz res = carregarMatriz("Tests/src/Resultados/subtrM.csv");
    Matriz t = subtrMatrizes(&m1, &m2);
    mu_assert("ERROR: FALHA NA OPERACAO DE SUBTRACAO DE MATRIZES", eqMatriz(&t, &res));
    clearMatriz(&m1); clearMatriz(&m2); clearMatriz(&res);
    return 0;
}

static char* MULTIPLICACAO_MATRIZES() {
    Matriz m1 = carregarMatriz("Tests/src/Matrizes/matriz_01.csv");
    Matriz m2 = carregarMatriz("Tests/src/Matrizes/matriz_02.csv");
    Matriz res = carregarMatriz("Tests/src/Resultados/multM.csv");
    Matriz m3 = multMatrizes(&m1, &m2);
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&m3, &res));
    clearMatriz(&m1); clearMatriz(&m2); clearMatriz(&m3); clearMatriz(&res);
    return 0;
}

static char* DETERMINANTE_MATRIZES_LAPLACE_3X3() {
    Matriz m = carregarMatriz("Tests/src/Matrizes/matriz_02.csv");
    float res = 0.0F;
    float fres = detMatrizSarrus(m);
    mu_assert("ERROR: FALHA NO CALCULO DE DETERMINANTES DE M 3X3", res == fres);
    clearMatriz(&m);
    return 0;
}

static char* DETERMINANTE_MATRIZES_LAPLACE_4X4() {
    Matriz m = carregarMatriz("Tests/src/Matrizes/matriz_03.csv");
    float res = 345761.0F;
    float fres = detMatrizLaplace(m);
    mu_assert("ERROR: FALHA NO CALCULO DE DETERMINANTES DE M 4X4", res == fres);
    clearMatriz(&m);
    return 0;
}

static char* all_tests() {
    mu_run_test(SOMA_ESCALAR_MATRIZ);
    mu_run_test(SUBTRACAO_ESCALAR_MATRIZ);
    mu_run_test(MULTIPLICACAO_ESCALAR_MATRIZ);
    mu_run_test(DIVISAO_ESCALAR_MATRIZ);
    mu_run_test(MULTIPLICACAO_MATRIZES);
    mu_run_test(DETERMINANTE_MATRIZES_LAPLACE_3X3);
    mu_run_test(DETERMINANTE_MATRIZES_LAPLACE_4X4);
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

// Comando de Compilação: gcc matriz.test.c  -o matrizTest
// Comando Run: ./"matrizTest.exe" 
