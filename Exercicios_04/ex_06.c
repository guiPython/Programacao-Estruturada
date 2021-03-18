#include <stdio.h>

void main ( void ){
    int x = 0 , y = 0 , z = 0 , val;
    for( int i = 0 ; i < 3 ; i++){
        for ( int j = 0 ; j < 3; j++){
            scanf("%d",&val);
            j == 0 ? x += val : 0;
            j == 1 ? y += val : 0;
            j == 2 ? z += val : 0;
        }
    }
    printf("%d %d %d",x,y,z);
}