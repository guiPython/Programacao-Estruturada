#include <stdio.h>
#include<stdlib.h>

void main(void){
    int qtd = -1, c = 0; 

    while(qtd < 0){
         scanf("%d",&qtd); 
         qtd < 0 ? printf("Numero deve ser POSITIVO! Digite um numero VALIDO!\n"):0;
    }

    printf("%d\n",qtd);

    int *vetor = (int *) malloc( qtd * sizeof(int) );

    while( c < qtd ){
        int n; scanf("%d",&n);
        if( n >= 2 ){  vetor[c] = n; c++; }
        else printf("Digite um numero >=2!\n");
    }

    for( int i = 0; i < qtd; i++ ) printf("%d ",vetor[i]);
}