#include <stdio.h>

float fcelsius(int Fahrenheit){
    return (float) ( Fahrenheit - 32 ) * 5/9;
}

void main(void){

    float fcelsius(int);
    int Fahrenheit;
    scanf("%d",&Fahrenheit);
    printf("%.2f",fcelsius(Fahrenheit));
    
}