#include <stdio.h>

void TrocaLetras( char *p ){
    for( int i = 0; i < 5; i++) *(p + i) = *(p + 5);
}

void main(void){
    char s[6], *p;
    p = s;

    for( int i = 0; i < 6; i++){
        scanf(" %c",p+i);
    }

    TrocaLetras(p);

    for( int i = 0; i < 5; i++){
        printf("%c",*(p+i));
    }
}