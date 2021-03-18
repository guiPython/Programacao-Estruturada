#include <stdio.h>

int multRec ( int maior , int menor ){
    if ( menor == 1 ) return maior;
    else return maior + multRec( maior , menor - 1);
}

void main ( void ){
    int x, y; scanf("%d\n%d",&x,&y);
    printf("%d", x > y ? multRec(x,y) : multRec(y,x) );
}