#include <stdio.h>

void main(void){
    int i;
    scanf("%d",&i);
    while ( i < 1 || i > 7 ){
        printf("O numero deve ser >=1 e <=7!\n");
        scanf("%d",&i);
    }
    
    switch (i){
        case 1:
            printf("Domingo");
            break;
        case 2:
            printf("Segunda-feira");
            break;
        case 3:
            printf("Terca-feira");
            break;
        case 4 :
            printf("Quarta-feira");
            break;
        case 5:
            printf("Quinta-feira");
            break;
        case 6:
            printf("Sexta-feira");
            break;
        default:
            printf("Sabado");
            break;
    }
}