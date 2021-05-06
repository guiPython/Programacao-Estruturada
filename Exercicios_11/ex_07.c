#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define tamArray 20

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

Lista *concat(Lista *fList, Lista *sList)
{
    Lista *list = fList;
    for (int i = 0; i < sList->qtd; i++)
    {
        insert(list, sList->num[i]);
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

void loadList(Lista *list)
{
    int element;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &element);
        insert(list, element);
    }
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int findElement(Lista *list, int element)
{
    for (int i = 0; i < list->qtd; i++)
    {
        if (list->num[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void changePositionElements(Lista *list, int e1, int e2)
{
    int index1, index2;
    index1 = findElement(list, e1);
    index2 = findElement(list, e2);

    if (index1 != -1 && index2 != -1)
    {
        swap(&list->num[index1], &list->num[index2]);
    }
}

void main(void)
{

    Lista *list = create();

    loadList(list);

    int e1, e2;
    scanf("%d\n%d", &e1, &e2);

    changePositionElements(list, e1, e2);
    Print(*list);
}