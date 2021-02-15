#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_COLS 15
#define MAX_ROWS 15



FILE* getArquivo(char* path){
    FILE *file = fopen(path,"r");
    if ( &file == NULL ){
        perror("ERROR:");
        exit(1);
    }
    return file;
}

void readMatriz(FILE *arq ,int **matriz, int *row,int *col){
    int i = 0;
    char *token;
    char line[1024];
    while(fgets(line,sizeof(line),arq)){
        int j = 0;
        for ( token = strtok(line,";") ; token && *token ; j++ , token = strtok(NULL,";")){
            matriz[i][j] = atoi(token);
        }
        *col = j;
        i++;
    }
    *row = i;
    fclose(arq);
}


void printMatriz(int **matriz , int *rows, int *cols){
    for( int i = 0 ; i < *rows ; i++){
        for ( int j = 0 ; j < *cols ; j++){
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}

int** buildMatriz(){
    int **matriz;
    matriz = (int **)malloc(MAX_ROWS * sizeof(int));
    for (int i = 0; i < MAX_ROWS; ++i){
	    matriz[i] = (int *)malloc(MAX_COLS * sizeof(int));
	}
    return matriz;
}


int main(void){

    // Funções 
    void readMatriz(FILE*,int**,int*,int*);
    void printMatriz(int**,int*,int*);

    // Atribuição Variaveis/Ponteiros
    int rows , cols;
    int **matriz = buildMatriz();
    FILE *file = getArquivo("teste.csv");

    // Execução de Funções
    readMatriz(file,matriz,&rows,&cols);
    printf("O arquivo csv tem %d linhas e %d colunas",rows,cols);
    printf("\n");
    printMatriz(matriz,&rows,&cols);
    return 0;
}

