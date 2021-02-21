#include <stdio.h>

int main(void){
    int n_alunos,n_alunas;
    scanf("%d\n%d",&n_alunas,&n_alunos);
    if ( n_alunos == n_alunas){ printf("Mesma quantidade!"); return 0;}
    else if ( n_alunos > n_alunas ){ printf("Quantidade de alunos eh maior do que de alunas!"); return 0;}
    printf("Quantidade de alunas eh maior do que de alunos!");
    return 0;
}