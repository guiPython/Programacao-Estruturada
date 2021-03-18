#include <stdio.h>

const char* semana[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado" };


void main(void){
    int n; scanf("%d",&n);
    printf("%s",semana[n]);
}