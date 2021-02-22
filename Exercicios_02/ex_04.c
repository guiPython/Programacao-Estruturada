#include <stdio.h>

int menor ( int num1 , int num2 ){
    return num1 < num2 ? num1 : num2;
}

int main(void){

    int menor(int,int);

    int operacao , mv , valor , num1 , num2 , num3 , count;
    scanf("%d",&operacao);

    if ( operacao == 0 ){
        printf("Nenhum calculo foi realizado!");
        return 0;
    }

    while( operacao != 0 ){
        scanf("%d",&num1);
        scanf("%d",&num2);
        switch(operacao){
            case 1:
                valor = num1 + num2;
                printf("(a+b) = %d\n",valor);
                break;
            case 2:
                scanf("%d",&num3);
                valor = num1 + num2 + num3;
                printf("(a+b+c) = %d\n",valor);
                break;
            case 3:
                valor = num1 * num2;
                printf("(a*b) = %d\n",valor);
                break;
        }
        if ( count == 0 ){ mv = valor; }
        mv = menor(valor,mv);
        scanf("%d",&operacao);
        count++;
    }
    printf("Menor resultado: %d",mv);
    return 0;
}