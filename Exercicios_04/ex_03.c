#include <stdio.h>

void main ( void ){
    int matriz[4][4] , maior10 = 0 , menor0 = 0;
    for ( int i = 0; i < 4; i++){
        for ( int j = 0 ; j < 4; j++){
            scanf("%i",&matriz[i][j]);
            matriz[i][j] > 10 ? maior10++ :0;
            matriz[i][j] < 0  ? menor0++  :0; 
        }
    }
    printf("Qtd. > 10: %d\nQtd. < 0: %d",maior10,menor0);
}