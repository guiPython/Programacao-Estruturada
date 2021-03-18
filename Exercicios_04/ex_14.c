#include <stdio.h>

int pot ( int x , int y){
    if ( y == 1 ) return x;
    else return x * pot(x,y-1);
}

void main ( void ){
    int x , y ; scanf("%d\n%d",&x,&y);
    printf("%d",pot(x,y));
}