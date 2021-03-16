#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../csv/csv.h"
#include "matriz.h"
#include "math.h"


static void allocMatriz(Matriz* m) {
    m->matriz = (float**)malloc(m->rows * sizeof(float));
    for (int i = 0; i < m->rows; ++i) {
        m->matriz[i] = (float*)malloc(m->cols * sizeof(float));
    }
}


static void loadMatriz(Matriz* m, FILE* arq) {
    int i = 0;
    char* token;
    char line[4096];
    int prevJ = -1;
    while (fgets(line, sizeof(line), arq)) {
        int j = 0;
        for (token = strtok(line, ";"); token && *token; token = strtok(NULL, ";")) {
            j++;
        }
        if (prevJ == -1) prevJ = j;
        else if (prevJ != j) kill("Erro: Matriz mal formada");
        i++;
    }
    m->rows = i;
    m->cols = prevJ;
    allocMatriz(m);
    rewind(arq);
    i = 0;
    while (fgets(line, sizeof(line), arq)) {
        int j = 0;
        for (token = strtok(line, ";"); token && *token; token = strtok(NULL, ";")) {
            m->matriz[i][j] = atof(token);
            j++;
        }
        i++;
    }
    fclose(arq);
}

Matriz prepMatriz(char *filePath){
    Matriz m ;
    FILE *file = getArquivo(filePath);
    loadMatriz(&m,file);
    return m;
}

Matriz copiarMatriz(Matriz* src)
{
    Matriz dest;
    dest.rows = src->rows;
    dest.cols = src->cols;
    allocMatriz(&dest);
    for (int i = 0; i < dest.rows; i++)
    {
        for (int j = 0; j < dest.cols; j++) 
        {
            float v = src->matriz[i][j];
            dest.matriz[i][j] = v;
        }
    }
    return dest;
}

Matriz criarMatrizDeMesmoTamanho(Matriz* src)
{
    Matriz dest;
    dest.rows = src->rows;
    dest.cols = src->cols;
    allocMatriz(&dest);
    return dest;
}

Matriz criarMatrizDeTamanho(int rows, int cols)
{
    Matriz dest;
    dest.rows = rows;
    dest.cols = cols;
    allocMatriz(&dest);
    return dest;
}


Matriz criarMatrizIdentidade(int n)
{
    Matriz dest = criarMatrizDeTamanho(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) dest.matriz[i][j] = 1;
            else dest.matriz[i][j] = 0;
        }
    }
    return dest;
}


void clearMatriz(Matriz *m){
    for( int i = 0 ; i < m->rows ; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

static void reduzirMatriz(Matriz* m, int a, int b, float fator) {
    if (m->rows < a || m->rows < b) kill("Erro: Numero de colunas eh menor do que os parametros passados.\n");

    for (int i = 0; i < m->cols; i++)
    {
        m->matriz[b][i] -= m->matriz[a][i] * fator;
    }
}

static void trocarLinhas(Matriz* m, int l1, int l2)
{
    if (m->rows <= l1 || m->rows <= l2) kill("Erro: Numero da linha é maior do que a quantidade de linhas da matriz");
    for (int i = 0; i < m->rows; i++) {
        float temp = m->matriz[l1][i];
        m->matriz[l1][i] = m->matriz[l2][i];
        m->matriz[l2][i] = temp;
    }
}

static void multLinha(Matriz* m, int l, float val)
{
    if (m->rows <= l) kill("Erro: Numero da linha é maior do que a quantidade de linhas da matriz");
    for (int i = 0; i < m->rows; i++)
    {
        m->matriz[l][i] *= val;
    }
}

int eqMatriz(Matriz *m1,Matriz *m2){
    if (m1->rows != m2->rows || m1->cols != m2->cols) { return 0;}
    else {
        for ( int i = 0 ; i < m1->rows ; i++){
            for ( int j = 0 ; j < m1->cols ; j++){
                if (m1->matriz[i][j] != m2->matriz[i][j]){
                    return 0;
                }
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


Matriz opEscalarMatriz(Matriz* m, float num, char op){
    Matriz res = criarMatrizDeMesmoTamanho(m);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if      (op == '*'){ res.matriz[i][j] = m->matriz[i][j] * (num); }
            else if (op == '+'){ res.matriz[i][j] = m->matriz[i][j] + (num); }
            else if (op == '-'){ res.matriz[i][j] = m->matriz[i][j] - (num); }
            else if (op == '/'){ res.matriz[i][j] = m->matriz[i][j] / (num); }
            else kill("Erro: Operecao nao definida");
        }
    }
    return res;
}

Matriz sumMatrizes(Matriz m1, Matriz m2){
    if (m1.rows != m2.rows || m1.cols != m2.cols) kill("As Matrizes M1 e M2 nao tem a mesma dimensao\n");
    else {
        Matriz res = criarMatrizDeMesmoTamanho(&m1);
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++) {
                res.matriz[i][j] = m1.matriz[i][j] + m2.matriz[i][j];
            }
        }
        return res;
    }
}

Matriz subtrMatrizes(Matriz m1, Matriz m2){
    if (m1.rows != m2.rows || m1.cols != m2.cols) kill("As Matrizes M1 e M2 nao tem a mesma dimensao\n");
    else{
        Matriz res = criarMatrizDeMesmoTamanho(&m1);
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++) {
                res.matriz[i][j] = m1.matriz[i][j] - m2.matriz[i][j];
            }
        }
        return res;
    }
}

Matriz multMatrizes(Matriz m1, Matriz m2){
    if (m1.cols != m2.rows) kill("Numero de colunas de M1 != Numero de linhas de M2.\n");
    else {
        Matriz res = criarMatrizDeTamanho(m1.rows, m2.cols);
        float val;
        for (int i = 0 ; i < m1.rows ; i++){
            for (int j = 0; j < m2.cols; j++){
                val = 0;
                for ( int k = 0 ; k < m1.cols ; k++) val += (m1.matriz[i][k]) * (m2.matriz[k][j]);
                res.matriz[i][j] = val;
            }
        }
        return res;
    }
}

Matriz inversaMatriz(Matriz* m) {
    if ((m)->cols != (m)->rows) kill("Erro: A matriz nao eh quadrada\n");
    Matriz copia = copiarMatriz(m);
    Matriz inversa = criarMatrizIdentidade(m->rows);
    for (int i = 0; i < copia.rows; i++)
    {
        for (int j = i + 1; j < copia.rows; j++)
        {
            if (copia.matriz[i][i] == 0) {
                for (int l = i + 1; l < copia.rows; l++)
                {
                    if (copia.matriz[l][l] != 0)
                    {
                        trocarLinhas(&copia, i, l);
                        break;
                    }
                }
                continue;
            }
            float fator = copia.matriz[j][i] / copia.matriz[i][i];
            reduzirMatriz(&inversa, i, j, fator);
            reduzirMatriz(&copia, i, j, fator);
        }
    }

    for (int i = copia.rows - 1; i > 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (copia.matriz[i][i] == 0) continue;
            if (j == -1) break;
            float fator = copia.matriz[j][i] / copia.matriz[i][i];
            reduzirMatriz(&inversa, i, j, fator);
            reduzirMatriz(&copia, i, j, fator);
        }
    }

    for (int i = 0; i < copia.rows; i++) {
        if (copia.matriz[i][i] == 0) continue;
        float fator = 1 / copia.matriz[i][i];
        multLinha(&inversa, i, fator);
        multLinha(&copia, i, fator);
    }

    clearMatriz(&copia);
    return inversa;
}

//https://pt.wikipedia.org/wiki/Teorema_de_Laplace
float detMatrizLaplace(Matriz m){
    if ( m.cols == 1 ){
        return m.matriz[0][0];
    }
    else{
        float detM = 0.0000F;
        for( int k = 0; k < m.cols ; k++){
            Matriz submatriz;
            submatriz = criarMatrizDeTamanho( m.rows -1,m.cols -1);
            int iaux = 0;
            int jaux = 0;
            if( m.matriz[1][k] != 0 ){
                for( int i = 1 ; i < m.rows ; i++){
                    for( int j =0 ; j < m.cols ; j++){
                        if ( j != k){
                            submatriz.matriz[iaux][jaux] = m.matriz[i][j];
                            jaux++;
                        }
                    }
                    iaux++;
                    jaux = 0;
                }
                float fator = k % 2 == 0 ? m.matriz[0][k] : -m.matriz[0][k];
                detM = detM + fator * detMatrizLaplace(submatriz);
                clearMatriz(&submatriz);
            }
        }
        return detM;
    }
}

