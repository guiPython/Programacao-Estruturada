#include <stdio.h>

typedef struct{
    char nome[75];
    int idade;
}Pessoa;

void __repr__(Pessoa p){
    printf("Nome: %s\nIdade: %d",p.nome,p.idade);
}

void main(void){
    Pessoa p;
    scanf("%s\n",p.nome);
    scanf("%d",&p.idade);
    __repr__(p);
}