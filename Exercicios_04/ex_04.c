#include <stdio.h>

void main ( void ){
    int m[3][3] , dp = 0 , ds = 0;
    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){
            scanf("%i",&m[i][j]);
            i == j ? dp += m[i][j] : 0;
        }
        ds += m[i][2-i];
    }
    printf("Soma diagonal principal: %d\nSoma diagonal secundaria: %d",dp,ds);
}