#include <stdio.h>

void main ( void ){
    int soma = 0 , val;
    for ( int i = 0 ; i < 4 ; i++){
        for ( int j = 0; j < 4; j++){
            scanf("%d",&val);
            if ( j < i ) soma += val;
        }
    }
    printf("Soma: %d",soma);
}