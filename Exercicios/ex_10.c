#include <stdio.h>

int main(void){
    int num;
    scanf("%d",&num);
    if ( num > 7 || num < 1){ printf("Numero Invalido!"); return 0;}
    switch (num)
    {
    case 1:
        printf("Domingo!");
        break;
    case 2:
        printf("Segunda-feira!");
        break;
    case 3:
        printf("Terça-feira!");
        break;
    case 4:
        printf("Quarta-feira!");
        break;
    case 5:
        printf("Quinta-feira!");
        break;
    case 6:
        printf("Sexta-feira!");
        break;
    default:
        printf("Sábado!");
        break;
    }
    return 0;
}