#include <stdio.h>
#include <stdlib.h>

char* inversa(char *str){
    char* strInv = NULL; strInv = malloc(5 * sizeof(char));
    for(int i = 4; i >= 0; i--) strInv[(i-4) < 0 ? (4-i) : (i-4)] = str[i];
    return strInv;
}

void main(void){
    char *strInv = NULL;
    char str[5];
    
    scanf("%s",str);
    strInv = inversa(str);

    for(int i = 0; i < 5; i++) printf("%c ",strInv[i]);
}