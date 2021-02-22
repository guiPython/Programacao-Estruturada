#include <stdio.h>

void main(void){

    int i ; int res = 0 ;
    scanf("%d",&i);

    int val = 1 ;
    while( val < i ){
        if ( i%val == 0 ){
            res += val;
        }
        val++;
    }
    printf("%d",res);
}