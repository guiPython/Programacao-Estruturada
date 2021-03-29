#include <stdio.h>

int funcao(float *vet, int N){
    int qtd = 0;
    for( int i = 0; i < N; i++) *(vet + i) < 0 ? qtd+=1 : 0;
    return qtd;
}

void main(void){
    int N;
    scanf("%d",&N);

    float vet[N]; float *p = NULL; p = vet;
    for( int i = 0; i < N; i++) scanf("%f",(p + i));

    printf("%d",funcao(p,N));
}