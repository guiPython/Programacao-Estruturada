#include<stdio.h>
#include<stdlib.h>

int** allocMatriz(int lin, int col){
    int **m = (int **) malloc( lin * sizeof(int) );
    for( int i = 0; i < col; i++) m[i] = (int *) malloc( col * sizeof(int) );
    return m;
}

void main(void){
    int lin, col, val, aux = 0, **m; scanf("%d\n%d\n%d",&lin,&col,&val);

    m = allocMatriz(lin, col);

    for( int i = 0; i < lin; i++){
        for( int j = 0; j < col; j++){
            scanf("%d",&m[i][j]);
            if( val == m[i][j] ) aux = 1 ;
        }
    }

    printf("%d",aux);
}