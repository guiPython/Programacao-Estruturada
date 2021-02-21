#include <stdio.h>

void main(void){
    int n;
    scanf("%d",&n);
    for ( int i = 0 ; i <= n ; i++ ){
        i % 2 != 0 ? printf("%d ",i) : 0;
    }
    printf("\n");
    for ( int j = 0 ; j <= n ; j++ ){
        j % 2 == 0 ? printf("%d ",j) : 0;
    }
}