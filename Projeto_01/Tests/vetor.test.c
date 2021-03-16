#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/vetor/vetor.h"
#include "../Libs/minUnit/minUnit.h"

int tests_run = 0;
float epsilon = 0.000001F;

static char* SOMA_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float n = 2.0F;
    Vetor u = opeEscVetor(n, v, '+');
    Vetor res = prepVetor("./src/Resultados/Vetores/soma.csv");
    mu_assert("ERROR: FALHA NA SOMA DO ESCALAR NOS ELEMENTOS DO VETOR",eqVetor(u,res));
    clearVetor(&v); 
    clearVetor(&u); 
    clearVetor(&res);
    return 0;
}

static char* SUBTRACAO_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float n = 2.0F;
    Vetor u = opeEscVetor(n, v, '-');
    Vetor res = prepVetor("./src/Resultados/Vetores/subtr.csv");
    mu_assert("ERROR: FALHA NA SUBTRACAO DO ESCALAR NOS ELEMENTOS DO VETOR", eqVetor(u, res));
    clearVetor(&v); clearVetor(&u); clearVetor(&res);
    return 0;
}

static char* MULTIPLICACAO_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float n = 2.0F;
    Vetor u = opeEscVetor(n, v, '*');
    Vetor res = prepVetor("./src/Resultados/Vetores/mult.csv");
    mu_assert("ERROR: FALHA NA MULTIPLICACAO DO ESCALAR NOS ELEMENTOS DO VETOR", eqVetor(u, res));
    clearVetor(&v); clearVetor(&u); clearVetor(&res);
    return 0;
}

static char* DIVISAO_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float n = 2.0F;
    Vetor u = opeEscVetor(n, v, '/');
    Vetor res = prepVetor("./src/Resultados/Vetores/divs.csv");
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DO VETOR", eqVetor(u, res));
    clearVetor(&v); clearVetor(&u); clearVetor(&res);
    return 0;
}

static char* MODULO_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float fres = moduloVetor(v); float res = 14.03566F;
    mu_assert("ERROR: FALHA EM CALCULAR O MODULO DO VETOR",((fres - res) < epsilon));
    clearVetor(&v);
    return 0;
}

static char* PRODUTO_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    Vetor u = prepVetor("./src/Vetores/vetor_02.csv");
    float fres = prodEscVetor(v, u); float res = 460124.0F;
    mu_assert("ERROR: FALHA NO PRODUTO ESCALAR ENTRE OS VETORES",((fres - res) < epsilon));
    clearVetor(&v); clearVetor(&u);
    return 0;
}

static char* all_tests() {
    mu_run_test(SOMA_ESCALAR_VETOR);
    mu_run_test(SUBTRACAO_ESCALAR_VETOR);
    mu_run_test(MULTIPLICACAO_ESCALAR_VETOR);
    mu_run_test(DIVISAO_ESCALAR_VETOR);
    mu_run_test(MODULO_VETOR);
    mu_run_test(PRODUTO_ESCALAR_VETOR);
    return 0;
}

int main(int argc, char** argv) {
    char* result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

// Comando de Compilação: gcc vetor.test.c  -o vetorTest
// Comando Run: ./"vetorTest.exe" 
