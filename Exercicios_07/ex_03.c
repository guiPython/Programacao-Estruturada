#include <stdio.h>

void DobroPrint(int *p){
    for( int i = 0; (p + i) < (p + 5); i++){
        printf("%d ",*(p+i) * 2);
    }
}

void main(void){
    int vetor[5];
    int *p = NULL; p = vetor;

    for( int i =0; (p + i) < (p + 5); i++){
        scanf("%d",(p+i));
    }

    DobroPrint(p);
}