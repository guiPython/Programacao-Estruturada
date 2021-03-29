#include <stdio.h>
#include <math.h>

void Calculadora(float *area, float* volume, float r){
    float pi = 3.14F;
    *area = 4 * pi * pow(r,2);
    *volume = (4 * pi * pow(r,3)) / 3;
}

void main(void){
    float area,volume,r;
    scanf("%f",&r);

    Calculadora(&area,&volume,r);

    printf("Area: %.2f\nVolume: %.2f",area,volume);
}