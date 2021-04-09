#include<stdio.h>
#include <stdlib.h>

int* funcao(int qtd){
    int *p=NULL;
    p=(int*) malloc(qtd*sizeof(int));
    return p;
}

void main(void){
    int *retP = NULL , qtd;
    scanf("%d",&qtd);

    retP = funcao(qtd);

    for(int i = 0; i < qtd; i++) scanf("%d",&retP[i]);

    for(int i = 0; i < qtd; i++) printf("%d ",retP[i]);
}