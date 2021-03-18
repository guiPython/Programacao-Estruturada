#include <stdio.h>

typedef struct{
    int id;
    char nome[75];
    float notas[3];
    float media;
}Aluno;

Aluno makeAluno(void){
    Aluno a;
    scanf("%d\n%s\n",&a.id,a.nome);
    for( int i = 0; i < 3; i++){
        scanf("%f",&a.notas[i]);
        a.media += a.notas[i];
    }
    a.media /= 3;
    return a;
}

void __repr__(Aluno a){
    printf("%d\n%s",a.id,a.nome);
    for( int i = 0; i < 3; i++){
        printf("\n%.1f",a.notas[i]);
    }
}

void main(void){

    Aluno list[4]; int idMaxMedia;
    for( int i = 0; i < 4; i++){
        list[i] = makeAluno();
        i == 0 ? idMaxMedia = 0 : list[i].media > list[idMaxMedia].media ? idMaxMedia = i : 0;
    }
    __repr__(list[idMaxMedia]);
}