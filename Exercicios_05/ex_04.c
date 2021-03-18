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
    Atleta list[4];
    int idMaxIdade = 0, idMaxAltura = 0;
    for( int i = 0; i < 4; i++){
        list[i] = makeAtleta();
        list[idMaxAltura].altura < list[i].altura ? idMaxAltura = i : 0;
        list[idMaxIdade].idade < list[i].idade ? idMaxIdade = i : 0;
    }
    printf("Mais alto: %s\nMais velho: %s",list[idMaxAltura].nome,list[idMaxIdade].nome);
}