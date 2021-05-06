#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct node *List;

List *create()
{
    List *list = (List *)malloc(sizeof(List));
    if (list != NULL)
    {
        *list = NULL;
    }
    return list;
}

bool append(List *list, int element)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = element;
    node->next = NULL;

    if (node == NULL)
    {
        return false;
    }
    else
    {
        if ((*list) == NULL)
        {
            *list = node;
            return true;
        }
        else
        {
            Node *nodeAux = *list;
            while (nodeAux->next != NULL)
            {
                nodeAux = nodeAux->next;
            }
            nodeAux->next = node;
            return true;
        }
    }
}

bool ehPar(int i)
{
    return i % 2 == 0 ? true : false;
}

bool ehMaior(int i, int j)
{
    return i > j ? true : false;
}

void calculadora(List *list)
{
    int qtdItens = 0, qtdPares = 0, maior = 0, posMaior = 0, soma = 0;
    double media = 0;

    Node *node = *list;

    while (node != NULL)
    {
        if (ehPar(node->value))
        {
            qtdPares++;
        }
        qtdItens++;

        soma += node->value;

        if (!ehMaior(maior, node->value))
        {
            maior = node->value;
            posMaior = qtdItens - 1;
        }

        node = node->next;
    }

    printf("a) Qtd. pares: %d \nb) Media: %.2f \nc) Maior: %d \nd) Posicao (Maior): %d \ne) Soma: %d",
           qtdPares, (double)soma / qtdItens, maior, posMaior, soma);
}

void main(void)
{
    List *list = create();

    for (int i = 0; i < 5; i++)
    {
        int element;
        scanf("%d", &element);
        append(list, element);
    }

    calculadora(list);
}