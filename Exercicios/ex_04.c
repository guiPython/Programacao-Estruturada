#include <stdio.h>
#include <stdbool.h>


const char* comparaAreaRetangulo(float areaA , float areaB){
    printf("A area do retangulo A eh: %f\nA area do retangulo B eh: %f", areaA, areaB);
    if ( areaA > areaB ){ return "\nA area do retangulo A eh maior do que a do retangulo B!";}
    else if ( areaB > areaA ){ return"\nA area do retangulo B eh maior do que a do retangulo A!";}
    return "\nA area do retangulo A eh igual ao do retangulo B!";
}

bool verificaRetangulo( float base , float altura ){
    if ( base == altura){ return false; }
    return true;
}

int main(void){
    bool verificaRetangulo(float,float);
    const char*  comparaAreaRetangulo(float,float);

    float base_retA , altura_retA , base_retB , altura_retB , areaA , areaB;
    scanf("%f\n%f\n%f\n%f",&base_retA,&altura_retA,&base_retB,&altura_retB);

    if ( !verificaRetangulo(base_retA,altura_retA) || !verificaRetangulo(base_retB,altura_retB) ){
        printf ("\nOs dados informados nao formam o retangulo A ou o retangulo B!");
        return 0;
    }
    printf("%s",comparaAreaRetangulo(altura_retA * base_retA,altura_retB * base_retB));
    return 0;
    
}