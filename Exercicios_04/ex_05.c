#include <stdio.h>
#include <math.h>

void main ( void ){
    int rows , cols; scanf("%d\n%d",&rows,&cols);
    int matriz[rows][cols];
    for ( int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            i < j ? matriz[i][j] = 2*i + 7*j - 2 : 0;
            i > j ? matriz[i][j] = 4 * pow(i,3) + 5 * pow(j,2) + 1 : 0;
            i == j ? matriz[i][j] = 3 * pow(i,2) - 1 : 0;
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}