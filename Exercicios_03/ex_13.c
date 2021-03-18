#include <stdio.h>
#include <string.h>

void main ( void ){
    char str[8];
    scanf("%s",str);
    while ( strlen(str) > 5)
    {
        printf("Digite novamente a string com ate 5 caracteres:\n");
        scanf("%s",str);
    }
    for( int i = strlen(str) ; i >= 0 ; i--){
        printf("%c ",str[i]);
    }
}