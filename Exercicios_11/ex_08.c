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

void swap(Node *a, Node *b)
{
    int aux = a->value;
    a->value = b->value;
    b->value = aux;
}

Node *findElementByIndex(List *list, int index)
{
    Node *node = *list;
    for (int i = 1; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

void changePositionElements(List *list, int i1, int i2)
{
    Node *node1, *node2;
    node1 = findElementByIndex(list, i1);
    node2 = findElementByIndex(list, i2);

    if (node1 != NULL && node2 != NULL)
    {
        swap(node1, node2);
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
    int i1, i2;
    List *list = create();

    for (int i = 0; i < 5; i++)
    {
        int element;
        scanf("%d", &element);
        append(list, element);
    }

    scanf("%d\n%d", &i1, &i2);
    changePositionElements(list, i1, i2);

    printList(list);
}