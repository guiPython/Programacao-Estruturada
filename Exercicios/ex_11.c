#include <stdio.h>

void setInteiros(int *n1 , int *n2){
    scanf("%d\n%d",n1,n2);
}

void setDoubles(double *n1 , double *n2){
    scanf("%lf\n%lf",n1,n2);
}

int main(void){
    void setInteiros(int*,int*);
    void setDoubles(double*,double*);

    int num , n1 ,n2;
    double n3 , n4;

    scanf("%d",&num);

    if ( num > 4 || num < 1){ printf("Numero Invalido!"); return 0;}
    switch (num)
    {
    case 1:
        setInteiros(&n1,&n2);
        printf("O resultado da soma eh: %d",(n1) + (n2));
        break;
    case 2:
        setInteiros(&n1,&n2);
        printf("O resultado da subtracao eh: %d",(n1) - (n2));
        break;
    case 3:
        setDoubles(&n3,&n4);
        printf("O resultado da divisao eh: %lf",(n3)/(n4));
        break;
    default:
        setInteiros(&n1,&n2);
        printf("O resultado da multiplicacao eh: %d",(n1) * (n2));
        break;
    }
    return 0;
}