#include <stdio.h>

void TrocaLetras( char *p, char x){
    for( int i = 0; i < 5; i++){
        *(p + i) = x;
    }
}

void main(void){
    char s[5], x, *p;
    p = s;

    for( int i = 0; i < 5; i++){
        scanf("%c\n",p+i);
    }

    scanf("%c",&x);

    TrocaLetras(p,x);

    for( int i = 0; i < 5; i++){
        printf("%c",*(p+i));
    }
}