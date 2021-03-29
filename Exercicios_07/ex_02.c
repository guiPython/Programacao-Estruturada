#include <stdio.h>

void main(void){
    int aux; int vetor[5];

    for( int i = 0; i < 5; i++){
        scanf("%d",&aux);
        if(aux % 2 == 0) vetor[i] = aux;
        else vetor[i] = 1;
    }

    for( int i = 0; i < 5; i++){
        if( vetor[i] != 1 ) printf("%d\n",vetor[i]);
    }

}