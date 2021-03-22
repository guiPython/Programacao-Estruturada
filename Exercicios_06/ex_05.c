#include <stdio.h>

void somaVal(int *n1, int *n2){
    *n1 += *n2;
}

void main(void){
    int n1,n2;
    scanf("%d\n%d",&n1,&n2);
    somaVal(&n1,&n2);
    printf("%d\n%d",n1,n2);
}