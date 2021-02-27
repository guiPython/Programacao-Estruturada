#include <stdio.h>
#include <stdlib.h>

FILE* getArquivo(char* path) {
    FILE* file = fopen(path, "r");
    if (&file == NULL) {
        perror("ERROR:");
        exit(1);
    }
    return file;
}
