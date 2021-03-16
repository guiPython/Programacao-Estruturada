#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

FILE* getArquivo(char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("ERROR:");
        exit(1);
    }
    return file;
}

void kill(const char* erro)
{
    printf("%s", erro);
    exit(0);
}

