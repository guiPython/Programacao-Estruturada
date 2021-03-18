#include <stdio.h>

int printN( int n , int aux ){
    if( aux > n ) return 1;
    else{
        printf("%d ",aux);
        printN(n , aux + 1);
    }
}

void main( void ){
    int n , aux = 0; scanf("%d",&n);
    printN(n,aux);
}