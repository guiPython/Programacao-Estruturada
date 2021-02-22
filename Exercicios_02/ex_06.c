#include <stdio.h>

float Hn(int i , float *res){
    for ( int j = 1 ; j <= i ; j++){
        *res += (float) 1/j;
    }
}

void main(void){

    float Hn(int,float*);

    float res = 0; int i;
    scanf("%d",&i);
    Hn(i,&res);
    printf("%.1f",res);

}