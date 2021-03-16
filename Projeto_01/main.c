#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Libs/csv/csv.h"
#include "Libs/matriz/matriz.h"
#include "Libs/vetor/vetor.h"

void desejaSalvarMatriz(Matriz* m)
{
erroSalvarMatriz:
	printf("Deseja salvar esta matriz em um arquivo? \n-> 1 Sim\n-> 0 Nao\n");
	int flag;
	scanf("%i", &flag);
	if (flag == 0) return;
	else if (flag == 1)
	{
		printf("Insira o nome do arquivo: ");
		char arq[1024];
		scanf("%s", arq);
		salvarMatriz(m, arq);
	}
	else
	{
		goto erroSalvarMatriz;
	}
}

void desejaSalvarVetor(Vetor* v)
{
erroSalvarVetor:
	printf("Deseja salvar este vetor em um arquivo? \n-> 1 Sim\n-> 0 Nao\n");
	int flag;
	scanf("%i", &flag);
	if (flag == 0) return;
	else if (flag == 1)
	{
		printf("Insira o nome do arquivo: ");
		char arq[1024];
		scanf("%s", arq);
		salvarVetor(v, arq);
	}
	else
	{
		goto erroSalvarVetor;
	}
}

int main(void) {
	char arqNome[2048];
	int verificador = -1;
	float num;
	printf("Bem vindo ao programa!\n");
	while (1) 
	{
	erro:
		printf("\nQual tipo de estrutura matematica voce quer utilizar? \n-> 1 para matrizes\n-> 2 para vetores\n-> Ou 3 para sair\n");
		scanf("%d", &verificador);
		if (verificador == 1)
		{
			printf("Insira o nome do arquivo que deseja utilizar: ");
			scanf("%s", arqNome);
			Matriz matriz1 = prepMatriz(arqNome);
			while (1) {
			erroMatriz:
				printf("\n--Operacoes Basicas -> 1\n--Operacoes Com Escalar -> 2\n--Inversa -> 3\n--Determinante -> 4\n--Voltar -> 5\n");
				scanf("%d", &verificador);
				Matriz matrizResultado;
				if (verificador == 1)
				{
					printf("Insira o nome do arquivo da outra matriz que deseja utilizar: ");
					scanf("%s", arqNome);
					Matriz matriz2 = prepMatriz(arqNome);
					while (1)
					{
					erroMatrizOperBasicaMatriz:
						printf("\n--Operacoes Basicas:\n ->Soma de matriz -> 1\n ->Subtracao de matriz -> 2\n ->Multiplicacao de matrizes -> 3\n ->Voltar -> 4\n");
						scanf("%d", &verificador);
						if (verificador == 1)
						{
							matrizResultado = sumMatrizes(matriz1, matriz2);
							printMatriz(&matrizResultado);
							desejaSalvarMatriz(&matrizResultado);
						}
						else if (verificador == 2)
						{
							matrizResultado = subtrMatrizes(matriz1, matriz2);
							printMatriz(&matrizResultado);
							desejaSalvarMatriz(&matrizResultado);
						}
						else if (verificador == 3)
						{
							matrizResultado = multMatrizes(matriz1, matriz2);
							printMatriz(&matrizResultado);
							desejaSalvarMatriz(&matrizResultado);
						}
						else if (verificador == 4)
						{
							clearMatriz(&matriz2);
							goto erroMatriz;
						}
						else
						{
							goto erroMatrizOperBasicaMatriz;
						}
					}
				}
				else if (verificador == 2) {
					printf("Digite o escalar do qual deseja realizar as operações.\n");
					scanf("%f", &num);
					while (1) {
					erroMatrizEscalar:
						printf("Qual operação deseja realizar?\n ->Adição -> 1\n ->Subtração -> 2\n ->Multiplicação -> 3\n ->Divisão -> 4\n ->Voltar -> 5\n");
						scanf("%d", &verificador);
						if (verificador == 1)
						{
							matrizResultado = opEscalarMatriz(&matriz1, num, '+');
							printMatriz(&matrizResultado);
							desejaSalvarMatriz(&matrizResultado);
						}
						else if (verificador == 2)
						{
							matrizResultado = opEscalarMatriz(&matriz1, num, '-');
							printMatriz(&matrizResultado);
							desejaSalvarMatriz(&matrizResultado);
						}
						else if (verificador == 3)
						{
							matrizResultado = opEscalarMatriz(&matriz1, num, '*');
							printMatriz(&matrizResultado);
							desejaSalvarMatriz(&matrizResultado);
						}
						else if (verificador == 4)
						{
							matrizResultado = opEscalarMatriz(&matriz1, num, '/');
							printMatriz(&matrizResultado);
							desejaSalvarMatriz(&matrizResultado);
						}
						else if (verificador == 5)
						{
							clearMatriz(&matrizResultado);
							goto erroMatriz;
						}
						else
						{
							goto erroMatrizEscalar;
						}
					}
				}
				else if (verificador == 3)
				{
					matrizResultado = inversaMatriz(&matriz1);
					printMatriz(&matrizResultado);
					desejaSalvarMatriz(&matrizResultado);
					clearMatriz(&matrizResultado);
				}
				else if (verificador == 4)
				{
					printf("%.4f\n", detMatrizLaplace(matriz1));
				}
				else if (verificador == 5)
				{
					clearMatriz(&matrizResultado);
					clearMatriz(&matriz1);
					goto erro;
				}
				else
				{
					clearMatriz(&matrizResultado);
					goto erroMatriz;
				}
			}
		}
		else if (verificador == 2)
		{
			printf("Insira o nome do arquivo que deseja utilizar: ");
			scanf("%s", arqNome);
			Vetor vetor1 = prepVetor(arqNome);
			while (1) {
			erroVetor:
				printf("\n--Operacoes Basicas -> 1\n--Modulo -> 2\n--Operacoes Complexas -> 3\n--Voltar -> 4\n");
				scanf("%d", &verificador);
				Vetor vetorResultado;
				if (verificador == 1)
				{
					printf("Digite o escalar do qual deseja realizar as operacoes: ");
					scanf("%f", &num);
					while (1) {
					erroOperBasicaVetor:
						printf("\n--Qual operacao deseja realizar?\n ->Adicao -> 1\n ->Subtracao -> 2\n ->Multiplicacao -> 3\n ->Divisao -> 4\n ->Voltar -> 5\n");
						scanf("%d", &verificador);
						if (verificador == 1) 
						{
							vetorResultado = opeEscVetor(num, vetor1, '+');
							printVetor(vetorResultado);
							desejaSalvarVetor(&vetorResultado);
						}
						else if (verificador == 2) 
						{
							vetorResultado = opeEscVetor(num, vetor1, '-');
							printVetor(vetorResultado);
							desejaSalvarVetor(&vetorResultado);
						}
						else if (verificador == 3) 
						{
							vetorResultado = opeEscVetor(num, vetor1, '*');
							printVetor(vetorResultado);
							desejaSalvarVetor(&vetorResultado);
						}
						else if (verificador == 4) 
						{
							vetorResultado = opeEscVetor(num, vetor1, '/');
							printVetor(vetorResultado);
							desejaSalvarVetor(&vetorResultado);
						}
						else if (verificador == 5) 
						{
							clearVetor(&vetorResultado);
							goto erroVetor;
						}
						else 
						{
							goto erroOperBasicaVetor;
						}
					}
				}
				else if (verificador == 2)
				{
					printf("%.4f\n", moduloVetor(vetor1));
				}
				else if (verificador == 3)
				{
					printf("Insira o nome do arquivo do outro vetor que deseja utilizar: ");
					scanf("%s", arqNome);
					Vetor vetor2 = prepVetor(arqNome);
					while (1) {
					erroVetorComplexo:
						printf("\n--Operacoes Complexas:\n ->Produto Escalar -> 1\n ->Produto Vetorial -> 2\n ->Angulo entre vetores -> 3\n ->Soma de Vetores -> 4\n ->Subtracao de Vetores -> 5\n ->Voltar -> 6\n");
						scanf("%d", &verificador);
						if (verificador == 1) 
						{
							printf("%.4f\n", prodEscVetor(vetor1, vetor2));
						}
						else if (verificador == 2) 
						{
							vetorResultado = prodVetVetor(vetor1, vetor2);
							printVetor(vetorResultado);
							desejaSalvarVetor(&vetorResultado);
						}
						else if (verificador == 3) 
						{
							printf("%.4f\n", angVetores(vetor1, vetor2));
						}
						else if (verificador == 4) 
						{
							vetorResultado = sumVetor(vetor1, vetor2);
							printVetor(vetorResultado);
							desejaSalvarVetor(&vetorResultado);
						}
						else if (verificador == 5) 
						{
							vetorResultado = subVetor(vetor1, vetor2);
							printVetor(vetorResultado);
							desejaSalvarVetor(&vetorResultado);
						}
						else if (verificador == 6) 
						{
							clearVetor(&vetor2);
							clearVetor(&vetorResultado);
							goto erroVetor;
						}
						else 
						{
							goto erroVetorComplexo;
						}
					}
				}
				else if (verificador == 4)
				{
					clearVetor(&vetor1);
					clearVetor(&vetorResultado);
					goto erro;
				}
				else
				{
					clearVetor(&vetorResultado);
					goto erroVetor;
				}
			}
		}
		else if (verificador == 3)
		{
			break;
		}
		else
		{
			goto erro;
		}
	}
	printf("Obrigado por usar o programa!\n");
	return 0;
}
