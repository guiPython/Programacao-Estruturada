#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/matriz/matriz.h"
#include "../Libs/vetor/vetor.h"
#include "../Libs/minUnit/minUnit.h"

int tests_run = 0;
const float epsilon = 0.0001F;

static char* SOMA_ESCALAR_MATRIZ() {
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/Matrizes/soma.csv");
    float num = 2.0F;
    Matriz m2 = opEscalarMatriz(&m, num, '+');
    mu_assert("ERROR: FALHA NA SOMA DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&m2, &res));
    clearMatriz(&m);  
    clearMatriz(&m2); 
    clearMatriz(&res);
    return 0;
}

static char* SUBTRACAO_ESCALAR_MATRIZ() {
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/Matrizes/subtr.csv");
    float num = 2.0F;
    Matriz m2 = opEscalarMatriz(&m, num, '-');
    mu_assert("ERROR: FALHA NA SUBTRACAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&m2, &res));
    clearMatriz(&m);  
    clearMatriz(&m2); 
    clearMatriz(&res);
    return 0;
}


static char* MULTIPLICACAO_ESCALAR_MATRIZ() {
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/Matrizes/mult.csv");
    float num = 2.0F;
    Matriz m2 = opEscalarMatriz(&m, num, '*');
    mu_assert("ERROR: FALHA NA MULTIPLICACAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&m2, &res));
    clearMatriz(&m);  
    clearMatriz(&m2); 
    clearMatriz(&res);
    return 0;
}

static char* DIVISAO_ESCALAR_MATRIZ() {
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/Matrizes/divs.csv");
    float num = 2.0F;
    Matriz m2 = opEscalarMatriz(&m, num, '/');
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&m2, &res));
    clearMatriz(&m); 
    clearMatriz(&m2);  
    clearMatriz(&res);
    return 0;
}

static char* ADICAO_MATRIZES() {
    Matriz m1 = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz m2 = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz m3 = sumMatrizes(m1, m2);
    Matriz res = prepMatriz("./src/Resultados/Matrizes/mult.csv");
    mu_assert("ERROR: FALHA NA OPERACAO DE SOMA DE MATRIZES", eqMatriz(&m3, &res));
    clearMatriz(&m1); 
    clearMatriz(&m2); 
    clearMatriz(&m3); 
    clearMatriz(&res);
    return 0;
}

static char* SUBTRACAO_MATRIZES() {
    Matriz m1 = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz m2 = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz m3 = subtrMatrizes(m1, m2);
    Matriz res = prepMatriz("./src/Resultados/Matrizes/subtrM.csv");
    mu_assert("ERROR: FALHA NA OPERACAO DE SUBTRACAO DE MATRIZES", eqMatriz(&m3, &res));
    clearMatriz(&m1); 
    clearMatriz(&m2); 
    clearMatriz(&m3); 
    clearMatriz(&res);
    return 0;
}

static char* MULTIPLICACAO_MATRIZES() {
    Matriz m1 = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz m2 = prepMatriz("./src/Matrizes/matriz_02.csv");
    Matriz m3 = multMatrizes(m1, m2);
    Matriz res = prepMatriz("./src/Resultados/Matrizes/multM.csv");
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DA MATRIZ", eqMatriz(&m3, &res));
    clearMatriz(&m1); 
    clearMatriz(&m2); 
    clearMatriz(&m3); 
    clearMatriz(&res);
    return 0;
}

static char* DETERMINANTE_MATRIZES_LAPLACE_3X3() {
    Matriz m = prepMatriz("./src/Matrizes/matriz_02.csv");
    float res = 0.0F;
    float fres = detMatrizLaplace(m);
    mu_assert("ERROR: FALHA NO CALCULO DE DETERMINANTES DE M 3X3", res == fres);
    clearMatriz(&m);
    return 0;
}

static char* DETERMINANTE_MATRIZES_LAPLACE_4X4() {
    Matriz m = prepMatriz("./src/Matrizes/matriz_03.csv");
    float res = 345761.0F;
    float fres = detMatrizLaplace(m);
    mu_assert("ERROR: FALHA NO CALCULO DE DETERMINANTES DE M 4X4", res == fres);
    clearMatriz(&m);
    return 0;
}

/*
static char* INVERSA_MATRIZ() {
    Matriz m = prepMatriz("./src/Matrizes/matriz_03.csv");
    Matriz fres = inversaMatriz(&m);
    Matriz res = prepMatriz("./src/Resultados/Matrizes/invM.csv");
    mu_assert("ERROR: FALHA NO CALCULO DA MATRIZ INVERSA", eqMatriz(&fres, &res));
    clearMatriz(&m);
    clearMatriz(&fres);
    clearMatriz(&res);
    return 0;
}
*/

static char* SOMA_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float n = 2.0F;
    Vetor u = opeEscVetor(n, v, '+');
    Vetor res = prepVetor("./src/Resultados/Vetores/soma.csv");
    mu_assert("ERROR: FALHA NA SOMA DO ESCALAR NOS ELEMENTOS DO VETOR", eqVetor(u, res));
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
    clearVetor(&v); 
    clearVetor(&u); 
    clearVetor(&res);
    return 0;
}

static char* MULTIPLICACAO_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float n = 2.0F;
    Vetor u = opeEscVetor(n, v, '*');
    Vetor res = prepVetor("./src/Resultados/Vetores/mult.csv");
    mu_assert("ERROR: FALHA NA MULTIPLICACAO DO ESCALAR NOS ELEMENTOS DO VETOR", eqVetor(u, res));
    clearVetor(&v); 
    clearVetor(&u); 
    clearVetor(&res);
    return 0;
}

static char* DIVISAO_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float n = 2.0F;
    Vetor u = opeEscVetor(n, v, '/');
    Vetor res = prepVetor("./src/Resultados/Vetores/divs.csv");
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DO VETOR", eqVetor(u, res));
    clearVetor(&v); 
    clearVetor(&u); 
    clearVetor(&res);
    return 0;
}

static char* MODULO_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    float fres = moduloVetor(v); float res = 14.03566F;
    mu_assert("ERROR: FALHA EM CALCULAR O MODULO DO VETOR", ((fres - res) < epsilon));
    clearVetor(&v);
    return 0;
}

static char* PRODUTO_ESCALAR_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_01.csv");
    Vetor u = prepVetor("./src/Vetores/vetor_02.csv");
    float fres = prodEscVetor(v, u); float res = 460124.0F;
    mu_assert("ERROR: FALHA NO PRODUTO ESCALAR ENTRE OS VETORES", ((fres - res) < epsilon));
    clearVetor(&v); 
    clearVetor(&u);
    return 0;
}

static char* PRODUTO_VETORIAL_VETOR() {
    Vetor v = prepVetor("./src/Vetores/vetor_03.csv");
    Vetor u = prepVetor("./src/Vetores/vetor_04.csv");
    Vetor fres = prodVetVetor(v, u);
    Vetor res = prepVetor("./src/Resultados/Vetores/prodVet.csv");
    mu_assert("ERROR: FALHA NO PRODUTO VETORIAl ENTRE OS VETORES", eqVetor(fres,res));
    clearVetor(&v); 
    clearVetor(&u); 
    clearVetor(&fres);  
    clearVetor(&res);
    return 0;
}

static char* ANGULO_VETORES() {
    Vetor v = prepVetor("./src/Vetores/vetor_03.csv");
    Vetor u = prepVetor("./src/Vetores/vetor_04.csv");
    float fres = angVetores(v, u);
    float res = 39.88848F;
    mu_assert("ERROR: FALHA NO CALCULO DO ANGULO ENTRE OS VETORES", ((fres - res) < epsilon));
    clearVetor(&v); 
    clearVetor(&u);
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
    //mu_run_test(INVERSA_MATRIZ);
    mu_run_test(SOMA_ESCALAR_VETOR);
    mu_run_test(SUBTRACAO_ESCALAR_VETOR);
    mu_run_test(MULTIPLICACAO_ESCALAR_VETOR);
    mu_run_test(DIVISAO_ESCALAR_VETOR);
    mu_run_test(MODULO_VETOR);
    mu_run_test(PRODUTO_ESCALAR_VETOR);
    mu_run_test(PRODUTO_VETORIAL_VETOR);
    mu_run_test(ANGULO_VETORES);
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

// Comando de Compilação: gcc tests.c  -o tests
// Comando Run: ./"tests.exe" 
