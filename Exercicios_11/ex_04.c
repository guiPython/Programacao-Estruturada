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

bool removeFirst(List *list)
{
    if (list == NULL)
    {
        return false;
    }

    else if ((*list) == NULL)
    {
        return false;
    }

    else
    {
        Node *nodeAux = *list;
        *list = nodeAux->next;
        free(nodeAux);
        return true;
    }
}

bool removeUp(List *list, int lastIndex)
{
    for (int i = 0; i < lastIndex; i++)
    {
        removeFirst(list);
    }
}

void printList(List *list)
{
    Node *node = *list;
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
}

void main(void)
{
    int lastIndex;
    List *list = create();

    for (int i = 0; i < 5; i++)
    {
        int element;
        scanf("%d", &element);
        append(list, element);
    }

    scanf("%d", &lastIndex);
    removeUp(list, lastIndex);

    printList(list);
}