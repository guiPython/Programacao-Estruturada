#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define max 20

typedef struct
{
    int qtd;
    int values[max];
} List;

List *create()
{
    List *list = (List *)malloc(sizeof(List));
    if (list != NULL)
    {
        list->qtd = 0;
    }
    return list;
}

bool append(List *list, int element)
{
    if (list == NULL)
    {
        return false;
    }
    else
    {
        if (list->qtd == max)
        {
            return false;
        }
        else
        {
            list->values[list->qtd] = element;
            list->qtd++;
            return true;
        }
    }
}

void load(List *list)
{
    int element;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &element);
        append(list, element);
    }
}

bool removeLast(List *list)
{
    if (list == NULL)
    {
        return false;
    }
    else
    {
        if (list->qtd == 0)
        {
            return false;
        }
        else
        {
            list->qtd--;
            return true;
        }
    }
}

void removeUp(List *list, int lastIndex)
{
    for (int i = 0; i < lastIndex; i++)
    {
        removeLast(list);
    }
}

void printList(List *list)
{
    for (int i = 0; i < list->qtd; i++)
    {
        printf("%d ", list->values[i]);
    }
}

void main(void)
{
    int lastIndex;
    List *list = create();
    load(list);

    scanf("%d", &lastIndex);
    removeUp(list, lastIndex);

    printList(list);
}