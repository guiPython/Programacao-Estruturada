#include <sdl.h>
#include <sdl_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "Libs/SnakeGame/food.h"
#include "Libs/SnakeGame/snake.h"
#include "Libs/SnakeGame/game.h"
#include <stdbool.h>
#include <locale.h> 
#include "Libs/Csv/csv.h"

//TODO Menu de resoluções


int main(void) {

	setlocale(LC_ALL,"Portuguese");

	SDL_Window* window;
	SDL_Renderer* renderer;
	FILE* file;

	file = fopen("./Libs/Files/score.csv","r");

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return 0;
	}

	window = SDL_CreateWindow("GAMES DOS MALUQUINHOS DE P.E", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 768, 768, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, 0);

	Game game;
	Cobra cobra;
	setupCobra(&cobra);

	Comida comida = { 0,0 };

	game.cobra = cobra;
	game.comida = comida;
	setupGame(&game);

	TTF_Init();
	SDL_Event event;


	while (game.status) {
		if (game.mainMenu) RunMainMenu(&game, renderer);
		if (game.scores) RunScore(&game, renderer, file);
		if (game.difMenu) RunDifMenu(&game, renderer);
		if (game.jogador) RunJogador(&game, renderer);
		if (game.partida) RunGame(&game, renderer, file);
		if (game.auxMenu) RunAuxMenu(&game, renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	printf("| GGIZI MEU PATRÃO | --- | OBRIGADO POR JOGAR |");


}
