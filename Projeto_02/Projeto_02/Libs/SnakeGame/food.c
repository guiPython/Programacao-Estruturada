#include "food.h"
#include "game.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ComidaSetPosicao(Comida* comida)
{
	srand(time(NULL)); // Gerador de n�meros aleat�rios

	int xAleatorio = 50 + (rand() % ( 670 - 50));   // 500px de Tela
	int yAleatorio = 160 + (rand() % (670 - 160)); // 500px de Tela

	// A posi��o se torna
	//xAleatorio -= xAleatorio % 10;
	//yAleatorio -= yAleatorio % 10;

	comida->pos.x = xAleatorio;
	comida->pos.y = yAleatorio;

	printf("| NOVA COMIDA NA POSIÇÃO ( X, Y ) = (%d, %d) |\n", comida->pos.x, comida->pos.y);
}

void ComidaAtualizacao(Game *game, SDL_Renderer* renderer)
{
	Comida comida = game->comida;
	SDL_Rect rComida = {comida.pos.x, comida.pos.y, COMPRIMENTO_COMIDA, LARGURA_COMIDA};
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rComida);
	SDL_RenderDrawRect(renderer, &rComida);
}