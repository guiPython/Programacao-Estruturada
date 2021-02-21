#include <stdio.h>

void main(void){
    int sony,dell,toshiba,total;
    scanf("%d\n%d\n%d",&sony,&dell,&toshiba);
    total = sony + dell + toshiba;
    printf("%d notebook(s) da Sony\n%d notebook(s) da Dell\n%d notebook(s) da Toshiba\nTotal de %d notebooks",sony,dell,toshiba,total);
}