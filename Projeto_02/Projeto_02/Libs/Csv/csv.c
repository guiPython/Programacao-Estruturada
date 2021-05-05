#include <stdio.h>
#include <stdlib.h>

FILE* getArquivo(char* path, char modo) {
    FILE* file = NULL;
    if (modo == 'r') {
        file = fopen(path, "r");
    }
    else if (modo == 'w') {
        file = fopen(path, "w");
    }
    return file;
}

void verificaScore(FILE* arq, int dificuldade, int score, char nome[3]) {
    char* aux;
    char linha[100];
    int cont, i, linhas = 0, pos = -1;
    if (arq == NULL) {
        arq = getArquivo("score.txt", 'w');
        cont = 0;
        char d = '0';
        for (int x = 0; x < 15; x++) {
            fputc(d, arq);
            fputs(";0;AAA\n", arq);
            cont += 1;
            if (cont == 5) {
                cont = 0;
                d++;
            }
        }
        fclose(arq);
        arq = getArquivo("score.txt", 'r');
    }
    while (fgets(linha, sizeof(linha), arq)) {
        i = 0;
        cont = 0;
        for (aux = strtok(linha, ";"); aux && *aux; aux = strtok(NULL, ";")) {
            if (cont == 0 && atoi(aux) == dificuldade) {
                i = 1;
            }
            if (i == 1 && cont == 1) {
                if (atoi(aux) <= score) {
                    pos = linhas;
                    goto achou;
                }
            }
            cont += 1;
        }
        linhas += 1;
    }
achou:
    rewind(arq);
    FILE* arqTemp = getArquivo("temp.txt", 'w');
    cont = 0;
    while (fgets(linha, sizeof(linha), arq)) {
        if ((pos <= 4 && cont == 4) || (pos <= 9 && pos > 4 && cont == 9) || (pos <= 14 && pos > 9 && cont == 15)) {
            cont++;
            continue;
        }
        if (cont == pos) {
            char buffer[32];
            fputc(dificuldade + '0', arqTemp);
            fputs(";", arqTemp);
            fputs(itoa(score, buffer, 10), arqTemp);
            fputs(";", arqTemp);
            fputs(nome, arqTemp);
            fputs("\n", arqTemp);
        }
        fputs(linha, arqTemp);
        cont++;
    }
    fclose(arq);
    fclose(arqTemp);
    arqTemp = getArquivo("temp.txt", 'r');
    arq = getArquivo("score.txt", 'w');
    cont = 0;
    while (fgets(linha, sizeof(linha), arqTemp) && cont < 15) {
        fputs(linha, arq);
        cont += 1;
    }
    fclose(arq);
    fclose(arqTemp);
    remove("temp.txt");
}