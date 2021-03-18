#include <stdio.h>
#include <string.h>


void main(void){
    char str[8]; int len;
    scanf("%s",str);
    len = strlen(str);
    while( len < 8){
        printf("Voce digitou uma string com %d caractere(s)!\n",len);
        printf("A string deve ter 8 caracteres. Por favor, digite uma nova string:\n");
        scanf("%s",str);
        len = strlen(str);
    }
    for ( int i = 0; i < 4; i++){
        printf("%c",str[i]);
    }
}