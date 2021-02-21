#include <stdio.h>

void main(void){
    int n;
    scanf("%d",&n);
    for( int i = 0 ; i <= n ; i++ ){
        printf("%d ",i);
    }
    printf("\n");
    while( n>=0 ) {
        printf("%d ",n);
        n--;
    }
}