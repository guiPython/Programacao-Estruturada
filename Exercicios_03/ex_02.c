#include <stdio.h>

void main(void){
    float notas[5] , media = 0;
    for( int i = 0; i < 5; i++){
        scanf("%f",&notas[i]);
        media += notas[i];
    }
    for( int j = 0; j < 5; j++){
        printf("%0.f ",notas[j]);
    }
    printf("\n%.2f",media/5);
}