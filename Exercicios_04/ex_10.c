#include<stdio.h>
#include<math.h>

int somaCubos( int n ){
    if (n == 1) return 1;
    else return pow(n,3) + somaCubos( n-1 );
}

void main ( void ){
    int n ; scanf("%d",&n);
    printf("%d",somaCubos(n));
}