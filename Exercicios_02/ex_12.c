#include <stdio.h>

void main(void){
    int n1,n2; char op;
    scanf("%d\n%d\n%c",&n1,&n2,&op);
    switch (op)
    {
    case '+':
        printf("%f",(float) n1 + n2);
        break;
    case '-':
        printf("%f",(float) n1 - n2);
        break;
    case '/':
        printf("%f",(float) n1 / n2);
        break;
    default:
        printf("%f",(float) n1 * n2);
        break;
    }
}