#include <stdio.h> 

void Maior_QtdMaior(int *maior, int *qtdMaior, int *vetor, int n){

    for( int i = 0; i < n; i++){
        if ( *maior < *(vetor + i) ) { *maior = *(vetor + i) ; *qtdMaior = 1; }
        else if (*maior == *( vetor + i ))
        {
            *qtdMaior+=1;
        }
        
    }

}

void main(void){
    int n, maior = 0, qtdMaior = 0;
    scanf("%d",&n);

    int vetor[n]; int *p = NULL; p = vetor;

    for( int i = 0; i < n; i++) scanf("%d",(p+i));

    Maior_QtdMaior(&maior,&qtdMaior,p,n);

    printf("O numero %d ocorreu %d vezes",maior,qtdMaior);
}