#include <stdbool.h>
#include <stdio.h>
#define tamArray 5

typedef struct
{
    int qtd;
    int num[tamArray];
} Lista;

Lista *create()
{
    Lista *list;
    list = (Lista *)malloc(sizeof(Lista));
    if (list != NULL)
    {
        list->qtd = 0;
    }
    return list;
}

bool insert(Lista *list, int element)
{
    if (list == NULL)
    {
        return false;
    }
    else
    {
        if (list->qtd == tamArray)
        {
            return false;
        }
        else
        {
            list->num[list->qtd] = element;
            list->qtd++;
            return true;
        }
    }
}

Lista concat(Lista *fList, Lista *sList)
{
    Lista list = *fList;
    list.qtd += sList->qtd;
    for (int i = 0; i < sList->qtd; i++)
    {
        insert(&list, sList->num[i]);
    }
    return list;
}

void Print(Lista list)
{
    for (int i = 0; i < list.qtd; i++)
    {
        printf("%d ", list.num[i]);
    }
}

void loadList(Lista *list, int aux)
{
    int element;
    for (int i = 0; i < aux; i++)
    {
        scanf("%d", element);
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

    scanf("%d", &aux);

    loadList(l2, aux);

    Print(concat(l1, l2));
}