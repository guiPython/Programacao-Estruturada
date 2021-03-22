#include <stdio.h>

void main(void){
    int x = 3; float y = 3.4F; char z = 'A';
    int *xptr = &x; float *yptr = &y; char *zptr = &z;
    printf("Antes:\nx = %d\ny = %f\nz = %c\n",*xptr,*yptr,*zptr);
    scanf("%d\n%f\n%c",&(*xptr),&(*yptr),&(*zptr));
    printf("Depois:\nx = %d\ny = %f\nz = %c",*xptr,*yptr,*zptr);
}