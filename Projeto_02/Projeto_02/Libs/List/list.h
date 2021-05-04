#ifndef LISTA
#define LISTA


typedef struct 
{
	char* valor;
	struct Item* proximo;
}Item;

void adicionar(struct Item** primeiro, char* valor);

void deletar(Item** primeiro, int pos);

#endif // !LISTA