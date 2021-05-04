#include "list.h"
#include <stdio.h>


void adicionar(Item** primeiro, char* valor) {

	Item* novoItem = (Item*)malloc(sizeof(Item));

	Item* ultimo = *primeiro;


	novoItem->valor = valor;

	novoItem->proximo = NULL;

	if (*primeiro == NULL)
	{
		*primeiro = novoItem;
		return;
	}

	while (ultimo->proximo != NULL)
		ultimo = ultimo->proximo;

	ultimo->proximo = novoItem;
	return;
}

void deletar( Item** primeiro, int pos)
{

    if (*primeiro == NULL)
        return;

    Item* temp = *primeiro;

    if (pos == 0)
    {
        *primeiro = temp->proximo;  
        free(temp);              
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->proximo;

    if (temp == NULL || temp->proximo == NULL)
        return;

    Item* proximo = temp->proximo;
    proximo = proximo->proximo;

    free(temp->proximo);

    temp->proximo = proximo;
}

