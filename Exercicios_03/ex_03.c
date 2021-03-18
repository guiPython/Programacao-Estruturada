#include <stdio.h>

void main(void){
    int x[6] = { 1, 0, 5, -2, -5, 7};
    int soma = x[0] + x[1] + x[5];
    x[4] = 100;
    printf("A soma eh: %d.",soma);
    for ( int i = 0 ; i < 6; i++){
        printf("\n%d",x[i]);
    }
}