#include <stdio.h>

void main ( void ){
    float vetor[10], num = 0 ; int j ;
    for ( int i = 0 ; i < 10 ; i++){
        scanf("%f",&num);
        j = i-1;
        while ( j >= 0 && vetor[j] > num)
        {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = num;
    }

    for ( int i = 0 ; i<10 ; i++){
        printf("%.1f\n",vetor[i]);
    }
}