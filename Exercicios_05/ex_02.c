#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}Ponto;

float dPontos(Ponto p1, Ponto p2){
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
}

void makePonto(Ponto *p){
    int x,y;
    scanf("%d\n%d",&x,&y);
    p->x = x; p->y = y;
}

void main(void){
    Ponto p1,p2;
    makePonto(&p1); makePonto(&p2);
    printf("%.1f",dPontos(p1,p2));
}