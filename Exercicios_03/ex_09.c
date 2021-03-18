#include <stdio.h>

int verRept(int list[10],int num,int index){
    for( int i = 0 ; i < index; i++){
        if( list[i] == num ){
            return 1;
        }
    }
    return 0;
}


void main(void){
    int vetor[10],i=0,aux=0;

    while ( i < 10 ){
        scanf("%d",&aux);
        if ( verRept(vetor,aux,i) == 1 ){
            printf("Numero já digitado! Digite outro numero!\n");
        }
        else{
            vetor[i] = aux;
            i++;
        }
    }

    for( int i = 0; i < 10 ; i++){
        printf("%d\n",vetor[i]);
    }
}