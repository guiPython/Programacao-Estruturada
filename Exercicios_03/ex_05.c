#include <stdio.h>

int verRept(int list[10],int num,int index){
    for( int i = 0 ; i <= index; i++){
        if( list[i] == num ){
            return 0;
        }
    }
    return 1;
}

void main(void){
    int verRept(int[10],int,int);
    int num,menor,maior=0,iP=0,iI=0,nums[10],par[10],imp[10];

    for( int i = 0; i < 10 ; i++){
        scanf("%d",&num);
        i == 0 ? menor = num : 0;
        if ( num % 2 == 0){
            if ( verRept(par,num,iP) ){
                par[iP] = num;
                iP++;
                menor > num ? menor = num:0;
                maior < num ? maior = num:0;
            }
        }
        else{
            if ( verRept(imp,num,iI) ){
                imp[iI] = num;
                iI++;
                menor > num ? menor = num:0;
                maior < num ? maior = num:0;
            }
        }
    }

    printf("Numeros Pares:");
    for ( int j = 0 ; j < iP ; j++){
        printf("\n%d",par[j]);
    }

    printf("\nNumeros Impares:");
    for ( int k = 0 ; k < iI ; k++){
        printf("\n%d",imp[k]);
    }
    printf("\nMaior:%d",maior);
    printf("\nMenor:%d",menor);
}