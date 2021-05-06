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

bool append(List *list, int e)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = e;
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
            Node *aux = *list;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
            return true;
        }
    }
}

bool Equals(List *first, List *second)
{
    Node *nodeF = *first;
    Node *nodeS = *second;
    while (nodeF != NULL || nodeS != NULL)
    {
        if ((nodeF->value != nodeS->value) || nodeF == NULL || nodeS == NULL)
        {
            return false;
        }

        nodeF = nodeF->next;
        nodeS = nodeS->next;
    }
    return true;
}

void load(List *list)
{
    for (int i = 0; i < 5; i++)
    {
        int element;
        scanf("%d", &element);
        append(list, element);
    }
}

void main(void)
{
    List *first = create();
    List *second = create();

    load(first);
    load(second);

    if (Equals(first, second))
        printf("Iguais!");
    else
        printf("Diferentes!");
}