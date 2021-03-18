#include <stdio.h>

int sumVetor(int index){
    int val;
    if ( index == 3 ){ 
        scanf("%d",&val);
        return val;
    }
    else{
        scanf("%d",&val);
        return val + sumVetor(index+1); 
    }
} 

void main ( void ){
    int index = 0;
    printf("%d",sumVetor(index));
}