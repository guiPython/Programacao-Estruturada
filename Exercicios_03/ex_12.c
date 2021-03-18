#include <stdio.h>

void main(void){
    char str[8]; int cont = 0;
    scanf("%s",str);
    while ( str[cont] != '\0' )
    {
        printf("%c\n",str[cont]);
        cont++;
    }
    printf("%d",cont);
}