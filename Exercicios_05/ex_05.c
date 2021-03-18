#include <stdio.h>

typedef struct  
{
    char nome[30];
    int idade;
    float altura;
}Atleta;

Atleta makeAtleta(void){
    Atleta a;
    scanf("%s\n%d\n%f",a.nome,&a.idade,&a.altura);
    return a;
}


void main(void){
    Atleta list[4]; int idades[4] , j = 4;
    for( int i = 0; i < 4; i++){
        list[i] = makeAtleta();
        j = i-1;
        while ( j >= 0 && idades[j] > list[i].idade)
        {
            idades[j+1] = idades[j];
            j--;
        }
        idades[j+1] = list[i].idade;
    }
    for( int i = 3; i >= 0; i--){
        printf("%d ",idades[i]);
    }
}