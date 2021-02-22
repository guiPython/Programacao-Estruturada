#include <stdio.h>

int main(void){
    
    int i;
    scanf("%d",&i);
    int n = 1;
    if ( i<0 ){ printf("Nao eh um quadrado perfeito!"); return 0;}
    while ( n*n <= i )
    {
        if( n*n == i ){
            printf("Eh um quadrado perfeito!");
            return 0;
        }
        n++;
    }
    printf("Nao eh um quadrado perfeito!"); 
    return 0;

}