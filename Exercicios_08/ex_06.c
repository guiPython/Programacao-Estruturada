#include<stdio.h>
#include<stdlib.h>

 int* allocVetor(int qtd){
    int *p=NULL;

    qtd > 0 ? p = (int*) malloc(qtd*sizeof(int)) : 0;

    return p;
}

void main(void){
    int *p = NULL, qtd;
    scanf("%d",&qtd);

    p = allocVetor(qtd);
    if (p == NULL) printf("Ponteiro NULL.");
    else printf("Ponteiro NAO NULL.");
}