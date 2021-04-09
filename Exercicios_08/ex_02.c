#include<stdio.h>
#include<stdlib.h>

void main(void){
    int qtd; scanf("%d",&qtd);

    int *vetor = (int *) malloc(sizeof(int) * qtd);

    for( int i = 0; i < qtd; i++){
        scanf("%d",&vetor[i]);
    }

    for( int j = 0; j < qtd; j++){
        printf("%d ",vetor[j]);
    }

    free(vetor);
}