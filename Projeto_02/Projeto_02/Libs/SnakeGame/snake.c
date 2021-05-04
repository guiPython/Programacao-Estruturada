#include "snake.h"
#include "game.h"
#include "food.h"
#include <SDL.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double DistanciaCobraComida(Game* game)
{
	double x, y;
	x = pow((double)game->cobra.cabeca.x - game->comida.pos.x, 2);
	y = pow((double)game->cobra.cabeca.y - game->comida.pos.y, 2);
	return sqrt(x + y);
}

double DistanciaCobra(Game* game, int i)
{
	double x = pow((double)game->cobra.cabeca.x - (double)game->cobra.calda[i].x, 2);
	double y = pow((double)game->cobra.cabeca.y - (double)game->cobra.calda[i].y, 2);
	return sqrt(x + y);
}

int CobraTamanho(Game* game)
{
	return game->cobra.tamanho;
}

void setupCobra(Cobra* cobra)
{
	cobra->cabeca.x = 160;
	cobra->cabeca.y = 160;
	cobra->calda = malloc(sizeof(Calda));
	cobra->tamanho = 0;
	cobra->largura = 20;	 // 20px largura
	cobra->comprimento = 20; // 20px comprimento
	cobra->direcao = 0;
}

void CobraMovimento(Game* game)
{
	for (int i = 0; i <= game->cobra.tamanho - 2; i++)
	{
		game->cobra.calda[i] = game->cobra.calda[i + 1];
	}

	Calda calda = {game->cobra.cabeca.x, game->cobra.cabeca.y};

	game->cobra.calda[game->cobra.tamanho - 1] = calda;

	switch (game->cobra.direcao)
	{
	case CIMA:
		game->cobra.cabeca.y -= game->cobra.velocidade;
		break;
	case BAIXO:
		game->cobra.cabeca.y += game->cobra.velocidade;
		break;
	case DIREITA:
		game->cobra.cabeca.x += game->cobra.velocidade;
		break;
	case ESQUERDA:
		game->cobra.cabeca.x -= game->cobra.velocidade;
		break;
	}
}

void CobraAtualizacao(Game* game, SDL_Renderer* renderer)
{
	Cobra cobra = game->cobra;
	SDL_Rect rCabecaCobra = {cobra.cabeca.x, cobra.cabeca.y, cobra.comprimento, cobra.largura};

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &rCabecaCobra);
	SDL_RenderFillRect(renderer, &rCabecaCobra);

	for (int i = 0; i <= cobra.tamanho - 1; i++)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_Rect rCaldaCobra = {cobra.calda[i].x, cobra.calda[i].y, cobra.comprimento, cobra.largura};
		SDL_RenderFillRect(renderer, &rCaldaCobra);
		SDL_RenderDrawRect(renderer, &rCaldaCobra);
	}
}

bool CobraColisao(Game game)
{
	Cobra cobra = game.cobra;
	if (cobra.cabeca.x < 45 || cobra.cabeca.y < 120)
		return true;
	if (cobra.cabeca.x > 680 || cobra.cabeca.y > 700)
		return true;
	return false;
}

void CobraCome(Game* game)
{
	double d = DistanciaCobraComida(game);
	if (d < game->tolerancia)
	{
		game->cobra.tamanho += 1;
		ComidaSetPosicao(&game->comida);
		Calda *calda = realloc(game->cobra.calda, (game->cobra.tamanho * sizeof(Calda)));

		if (calda != NULL)
		{
			game->cobra.calda = calda;
			Calda nCalda = {game->cobra.cabeca.x, game->cobra.cabeca.y};
			game->cobra.calda[game->cobra.tamanho - 1] = nCalda;
			printf("\n| COMEU TUDO PARABENS |\n");
		}
	}
}

void CobraMorte(Game* game)
{
	if (CobraColisao(*game))
	{
		Init(game);
		printf("\n| PRESTA ATENÇÃO NA PAREDE | --- | VACILÃO |\n");
	}
	for (int i = 0; i < game->cobra.tamanho; i++)
	{
		double d = DistanciaCobra(game, i);
		if (d < 1)
		{
			Init(game);
			printf("\n| PRESTA ATENÇÃO | --- | VACILÃO |\n");
		}
	}
}