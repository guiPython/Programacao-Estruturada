#include <stdio.h>

void PrintSoma( int *m ){
    for( int i = 0; i < 9; i++) printf("%d\n",*(m + i) + 1);
}

void main(void){
    int m[3][3];
    int *p = m;

    for( int i = 0; i < 9; i++) scanf("%d",(p+i));

    PrintSoma(p);
}