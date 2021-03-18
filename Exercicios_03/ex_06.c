#include <stdio.h>

void main( void ){
    float x[5],soma=0;
    int aux=0;
    for ( int i = 0; i<5; i++){
        scanf("%f",&x[i]);
        if ( x[i] < 0 ){ aux++; }
        else{ soma += x[i]; }
    }
    printf("%d\n%f",aux,soma);
}