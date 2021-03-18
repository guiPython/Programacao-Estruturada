#include <stdio.h>

void main(void){
    int x[8],i1,i2;
    for( int i = 0; i < 8; i++){
        scanf("%d",&x[i]);
    }
    scanf("\n%d",&i1);
    while (0 > i1 || i1 >=8)
    {
        printf("Valor de X invalido!\n");
        scanf("%d",&i1);
    }
    scanf("\n%d",&i2);
    while(0 > i2 || i2 >= 8){
        printf("Valor de Y invalido!\n");
        scanf("%d",&i2);
    }
    printf("Soma eh: %d",x[i1]+x[i2]);
}