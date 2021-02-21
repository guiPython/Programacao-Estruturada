#include <stdio.h>

void main(void){
    int num;
    scanf("%d",&num);
    printf("Antecessor de %d eh: %d\nSucessor de %d eh: %d",num,num-1,num,num+1);
}