#include <stdio.h>

int verRept(int list[6],int num,int index){
    for( int i = 0 ; i < index; i++){
        if( list[i] == num ){
            return 1;
        }
    }
    return 0;
}

void main ( void ){
    int vetor[6],vetorRep[3];
    int cont=0;
    for ( int i = 0 ; i < 6 ; i++){
        scanf("%d",&vetor[i]);
        if( verRept(vetor,vetor[i],i) == 1 ){
            if( verRept(vetorRep,vetor[i],cont) == 0 ){
                vetorRep[cont] = vetor[i];
                cont++;
            }
        }
    }

    if( cont != 0 ){
        for ( int i = 0; i < cont ; i++){
            printf("\n%d",vetorRep[i]);
        }
    }
    else{
        printf("Nao existem valores iguais!");
    }

} 