#include <stdio.h>
#include <string.h>


void cont_trans_Vog(char str[8], int *cont , char x){
    char vog [5] = {'a','e','i','o','u'};
    for ( int i = 0 ; i < strlen(str); i++){
        for( int j = 0 ; j < 5; j++){
            if( str[i] == vog[j] ){
                str[i] = x;
                (*cont)++;
            }
        }
    }
}

void main ( void ){
    void cont_trans_Vog(char*,int*,char);
    char str[8]; int cont = 0; char x;

    scanf("%s\n%c",str,&x);

    cont_trans_Vog(str,&cont,x);

    printf("A string possui %d vogais.\n",cont);
    printf("%s",str);
}