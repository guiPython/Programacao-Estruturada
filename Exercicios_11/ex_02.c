#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define tamArray 20

struct element
{
    int num;
    struct element *prox;
};

typedef struct element Elemt;

typedef struct element *Lista;

Lista *create()
{
    Lista *list;
    list = (Lista *)malloc(sizeof(Lista));
    if (list != NULL)
    {
        *list = NULL;
    }
    return list;
}

bool insert(Lista *list, int element)
{

    Elemt *no;
    no = (Elemt *)malloc(sizeof(Elemt));
    if (no == NULL)
    {
        return false;
    }
    no->num = element;
    no->prox = NULL;
    if ((*list) == NULL)
    {
        *list = no;
        return true;
    }
    else
    {
        Elemt *aux;
        aux = *list;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
        return true;
    }
}

Lista *concat(Lista *fList, Lista *sList)
{
    Lista *list = fList;
    Elemt *aux = *sList;
    while (aux != NULL)
    {
        insert(list, aux->num);
        aux = aux->prox;
    }
    return list;
}

void Print(Lista *list)
{
    Elemt *aux = *list;
    while (aux != NULL)
    {
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}

void loadList(Lista *list, int aux)
{
    int element;
    for (int i = 0; i < aux; i++)
    {
        scanf("%d", &element);
        insert(list, element);
    }
}

void main(void)
{
    int aux;
    scanf("%d", &aux);

    Lista *l1 = create();
    Lista *l2 = create();

    loadList(l1, aux);

    Print(l1);
    printf("\n");

    scanf("%d", &aux);

    loadList(l2, aux);

    Print(l2);
    printf("\n");

    Print(concat(l1, l2));
}