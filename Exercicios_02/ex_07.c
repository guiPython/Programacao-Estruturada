#include <stdio.h>

void triangFloyd( int i ){
    int aux = 1; 
    for ( int j = 0 ; j < i ; j++ ){
        for ( int k = 0 ; k <= j ; k++ ){
            printf("%d ",aux);
            aux++;
        }
        printf("\n");
    }
}   

void main(void){

    int i;
    scanf("%d",&i);
    triangFloyd(i);

}