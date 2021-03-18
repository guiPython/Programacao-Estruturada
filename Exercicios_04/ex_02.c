#include <stdio.h>

void main ( void ){
    int n; scanf("%d",&n);
    int m[n][n];
    for ( int x = 0; x < n; x++){
        for ( int y = 0; y < n; y++){
            m[x][y] = x == y ?  1 : 0;
            printf("%d ",m[x][y]);
        }
        printf("\n");
    }
}