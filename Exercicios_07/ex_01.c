#include <stdio.h>

void printVetor(int *pvetor){
    for( int i = 0; i < 5; i++){
        printf("%d ",*pvetor);
        pvetor++;
    }
}

void main (void){
    int vet[5];
    for( int i = 0; i < 5; i++){
        scanf("%d",&vet[i]);
    }
    int *p = NULL;
    p = vet;
    printVetor(p);
}