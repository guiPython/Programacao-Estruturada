#ifndef GAME
#define GAME

#include <stdbool.h>
#include "../List/list.h"

typedef struct {
	int x, y;
}Cabeca;

typedef struct {
	int x, y;
} Calda;

typedef struct
{
	Cabeca cabeca;
	int largura, comprimento;
	int tamanho;
	int direcao;
	int velocidade;
	Calda* calda;
} Cobra;

typedef struct
{
	int x, y;
} Posicao;


typedef struct
{
	Posicao pos;
} Comida;


typedef struct {
	Cobra cobra;
	Comida comida;
	bool status;
	bool mainMenu;
	bool difMenu;
	bool jogador;
	bool partida;
	bool auxMenu;
	bool scores;
	Item* nomeJogador;
	double bonus;
	int tolerancia;
}Game;

void setupGame(Game* game);

void Init(Game* game);

void InfoGame(Game* game, char* str);

double GameBonus(Game* game);

void RenderInfoGame(SDL_Renderer* renderer, char* message);

void RenderMenuGame(SDL_Renderer* renderer, char arr[][20], int i);

void RunMainMenu(Game* game, SDL_Renderer* renderer);

void RunDifMenu(Game* game, SDL_Renderer* renderer);

void RenderJogador(Game* game, SDL_Renderer* renderer, char arr[][100], int aux, bool pipe);

void RunJogador(Game* game, SDL_Renderer* renderer);

void RenderParede(SDL_Renderer* renderer);

void RunGame(Game* game, SDL_Renderer* renderer);

void RunAuxMenu(Game* game, SDL_Renderer* renderer);

#endif // !GAME