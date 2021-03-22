#include <stdio.h>

void trocaVal(int *n1, int *n2){
    if (*n2 > *n1) {
        int aux = *n1;
        *n1 = *n2;
        *n2 = aux;
    }
}

void main(void){
    void trocaVal(int*,int*);
    int n1,n2;
    scanf("%d\n%d",&n1,&n2);
    trocaVal(&n1,&n2);
    printf("%d\n%d",n1,n2);
}