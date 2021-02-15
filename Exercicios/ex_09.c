#include <stdio.h>

int main(void){
    int a , b ;
    scanf("%d\n%d",&a,&b);
    if ( a == b ){ printf("Numeros Iguais!"); return 0;}
    printf("O %d eh o maior numero!", a > b ? a : b);
    return 0;
}