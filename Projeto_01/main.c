#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Libs/csv/csv.h"
#include "Libs/matriz/matriz.h"
#include "Libs/vetor/vetor.h"

int main(void){
    int verificador = -1;
    float num;
    printf("Bem vindo ao programa!\n");
    while(1){
        erro:
        printf("Qual tipo de estrutura matematica você quer utilizar? \n-> 1 para matrizes\n-> 2 para vetores\n-> Ou 3 para sair\n");
        scanf("%d", &verificador);
        if(verificador == 1){
            Matriz matriz1 = prepMatriz("Source/Matrizes/matriz1.csv");
            Matriz matrizResultado;
            while(1){
                erroMatriz:
                printf("--Operações Básicas -> 1\n--Operações Com Escalar -> 2\n--Inversa -> 3\n--Determinante -> 4\n--Voltar -> 5\n");
                scanf("%d", &verificador);
                if(verificador == 1){
                    Matriz matriz2 = prepMatriz("Source/Matrizes/matriz2.csv");
                    while(1){
                        erroMatrizOperBasicaMatriz:
                        printf("--Operações Básicas:\n ->Soma de matriz -> 1\n ->Subtração de matriz -> 2\n ->Multiplicação de matrizes -> 3\n ->Voltar -> 4\n");
                        scanf("%d", &verificador);
                        if(verificador == 1){
                            matrizResultado = sumMatrizes(matriz1, matriz2);
                            printMatriz(&matrizResultado);
                        }else if(verificador == 2){
                            matrizResultado = subtrMatrizes(matriz1, matriz2);
                            printMatriz(&matrizResultado);
                        }else if(verificador == 3){
                            matrizResultado = multMatrizes(matriz1, matriz2);
                            printMatriz(&matrizResultado);
                        }else if(verificador == 4){
                            goto erroMatriz;
                        }else{
                            goto erroMatrizOperBasicaMatriz;
                        }
                    }
                }else if(verificador == 2){
                    printf("Digite o escalar do qual deseja realizar as operações.\n");
                    scanf("%f", &num);
                    while(1){
                        erroMatrizEscalar:
                        printf("Qual operação deseja realizar?\n ->Adição -> 1\n ->Subtração -> 2\n ->Multiplicação -> 3\n ->Divisão -> 4\n ->Voltar -> 5\n");
                        scanf("%d", &verificador);
                        if(verificador == 1){
                            matrizResultado = opEscalarMatriz(&matriz1, num, '+');
                            printMatriz(&matrizResultado);
                        }else if(verificador == 2){
                            matrizResultado = opEscalarMatriz(&matriz1, num, '-');
                            printMatriz(&matrizResultado);
                        }else if(verificador == 3){
                            matrizResultado = opEscalarMatriz(&matriz1, num, '*');
                            printMatriz(&matrizResultado);
                        }else if(verificador == 4){
                            matrizResultado = opEscalarMatriz(&matriz1, num, '/');
                            printMatriz(&matrizResultado);
                        }else if(verificador == 5){
                            goto erroMatriz;
                        }else{
                            goto erroMatrizEscalar;
                        }
                    }
                }else if(verificador == 3){
                    matrizResultado = inversaMatriz(&matriz1);
                    printMatriz(&matrizResultado);
                }else if(verificador == 4){
                    printf("%.4f\n", detMatrizLaplace(matriz1));
                }else if(verificador == 5){
                    goto erro;
                }else{
                    goto erroMatriz;
                }
            }
        }else if(verificador == 2){
            Vetor vetor1 = prepVetor("Source/Vetores/vetor1.csv");
            Vetor vetorResultado;
            while(1){
                erroVetor:
                printf("--Operações Básicas -> 1\n--Módulo -> 2\n--Operações Complexas -> 3\n--Voltar -> 4\n");
                scanf("%d", &verificador);
                if(verificador == 1){
                    printf("Digite o escalar do qual deseja realizar as operações.\n");
                    scanf("%f", &num);
                    while(1){
                        erroOperBasicaVetor:
                        printf("Qual operação deseja realizar?\n ->Adição -> 1\n ->Subtração -> 2\n ->Multiplicação -> 3\n ->Divisão -> 4\n ->Voltar -> 5\n");
                        scanf("%d", &verificador);
                        if(verificador == 1){
                            Vetor vetorResultado = opeEscVetor(num, vetor1, '+');
                            printVetor(vetorResultado);
                        }else if(verificador == 2){
                            Vetor vetorResultado = opeEscVetor(num, vetor1, '-');
                            printVetor(vetorResultado);
                        }else if(verificador == 3){
                            Vetor vetorResultado = opeEscVetor(num, vetor1, '*');
                            printVetor(vetorResultado);
                        }else if(verificador == 4){
                            Vetor vetorResultado = opeEscVetor(num, vetor1, '/');
                            printVetor(vetorResultado);
                        }else if(verificador == 5){
                            goto erroVetor;
                        }else{
                            goto erroOperBasicaVetor;
                        }
                    }
                }else if(verificador == 2){
                    printf("%.4f\n", moduloVetor(vetor1));
                }else if(verificador == 3){
                    Vetor vetor2 = prepVetor("Source/Vetores/vetor2.csv");
                    while(1){
                        erroVetorComplexo:
                        printf("--Operações Complexas:\n ->Produto Escalar -> 1\n ->Produto Vetorial -> 2\n ->Ângulo entre vetores -> 3\n ->Soma de Vetores -> 4\n ->Subtração de Vetores -> 5\n ->Voltar -> 6\n");
                        scanf("%d", &verificador);
                        if(verificador == 1){
                            printf("%.4f\n", prodEscVetor(vetor1, vetor2));
                        }else if(verificador == 2){
                            vetorResultado = prodVetVetor(vetor1, vetor2);
                            printVetor(vetorResultado);
                        }else if(verificador == 3){
                            printf("%.4f\n", angVetores(vetor1, vetor2));
                        }else if(verificador == 4){
                            printf("A FAZER\n");
                        }else if(verificador == 5){
                            printf("A FAZER\n");
                        }else if(verificador == 6){
                            goto erroVetor;
                        }else{
                            goto erroVetorComplexo;
                        }
                    }
                }else if(verificador == 4){
                    goto erro;
                }else{
                    goto erroVetor;
                }
            }
        }else if(verificador == 3){
            break;
        }else{
            goto erro;
        }
    }
    printf("Obrigado por usar o programa!\n");
    return 0;
}
