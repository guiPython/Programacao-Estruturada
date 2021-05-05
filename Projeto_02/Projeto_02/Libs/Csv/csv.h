#ifndef CSV
#define CSV

#include <stdio.h>
#include <stdlib.h>

FILE* getArquivo(char* path, char modo);
void verificaScore(FILE* arq, int dificuldade, int score, char nome[3]);

#endif 
