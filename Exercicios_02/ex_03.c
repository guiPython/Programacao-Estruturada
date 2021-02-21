#include <stdio.h>

void main(void){
    int n;
    scanf("%d",&n);
    int c = 0;
    while( n < 0 ){ 
        scanf("%d",&n);
        c++;
    }
    while( c > 0){
        printf("O numero deve ser >=0!\n");
        c--;
    }
    for ( int i = 0 ; i <= n ; i++ ){
        printf("%d ",n-i);
    }
    printf("\nFIM!");
}