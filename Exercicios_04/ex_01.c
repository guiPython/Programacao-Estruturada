# include <stdio.h>

typedef struct{
    int val;
    int x;
    int y;
} Num;


void main ( void ){
    int m[3][3] ; Num maior ; Num menor;
    maior.x = 0; maior.y = 0;
    menor.x = 0;menor.y = 0;
    for( int i = 0 ; i < 3 ; i++){
        for ( int j = 0; j < 3; j++){
            scanf("%i",&m[i][j]);
            i == 0 & j == 0 ? menor.val = m[0][0] : 0;
            i == 0 & j == 0 ? maior.val = m[0][0] : 0;
            if ( m[i][j] > maior.val ) { maior.val = m[i][j] ; maior.x = i ; maior.y = j; }
            if ( m[i][j] < menor.val ) { menor.val = m[i][j] ; menor.x = i ; menor.y = j; }
        }
    }
    printf("Maior: %d\nPosicao (maior): %d linha e %d coluna\n",maior.val,maior.x,maior.y);
    printf("Menor: %d\nPosicao (menor): %d linha e %d coluna",menor.val,menor.x,menor.y);
}