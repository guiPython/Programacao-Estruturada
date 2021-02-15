#include <stdio.h>

void main(void){
    float pg1 , pg2 , pg3;
    pg1 = 0.46 * 780.00 ; pg2 = 0.32 * 780.00 ; pg3 = 780 * (1 - (0.78));
    printf("Primeiro ganhador: R$ %.2f\nSegundo ganhador: R$ %.2f\nTerceiro ganhador: R$ %.2f",pg1,pg2,pg3);
}