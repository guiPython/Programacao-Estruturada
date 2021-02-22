#include <stdio.h>

void H (int i , float *res){
    int fatorial = 1;
    for ( int j = 1 ; j <= i ; j++ ){
        for ( int k = j ; k > 0 ; k-- ){
            fatorial *= k;
        }
        *res += (float) 1/fatorial;
        fatorial = 1;
    }
}

void main(void){

    void H (int,float*);
    int i; float res;
    scanf("%d",&i);
    H(i,&res);
    printf("%f",res);
}