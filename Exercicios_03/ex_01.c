#include <stdio.h>

void main ( void ){
    int vetor[6];
    for ( int x = 5; x >= 0; x--){
        scanf("%d",&vetor[x]);
    }
    for ( int y = 0; y < 6; y++){
        printf("%d ",vetor[y]);
    }
}