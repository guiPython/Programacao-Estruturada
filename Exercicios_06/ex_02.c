#include <stdio.h>

void main(void){
    int x = 2 , y = 5;
    &x > &y ? printf("A") : printf("B");
}