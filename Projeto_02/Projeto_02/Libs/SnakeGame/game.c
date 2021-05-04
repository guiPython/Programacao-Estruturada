#include <SDL.h>
#include <sdl_ttf.h>
#include <string.h>
#include "food.h"
#include "snake.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

//TODO MAINMENU , MENU status 0 , 1 ou 2;

double GameBonus(Game* game) {
	int i = 0; double bonus = 0;
	while (i <= game->cobra.tamanho) {
		bonus += 0.5;
		i += 20;
	}
	return game->bonus = 1 + bonus;
}

void setupGame(Game* game) {
	game->mainMenu = true;
	game->difMenu = false;
	game->jogador = false;
	game->partida = false;
	game->auxMenu = false;
	game->scores = false;
	game->bonus = 1;
	game->status = true;
}

void Init(Game* game) {
	setupGame(game);
	setupCobra(&game->cobra);
	ComidaSetPosicao(&game->comida);
}

void InfoGame(Game* game, char* str) {
	int pontosBruto = (int)(CobraTamanho(game));
	int pontos = pontosBruto % 2 == 0 ? pontosBruto : pontosBruto - 1;
	double bonus = GameBonus(game);

	char nome[12] = " ";
	int i = 0;
	Item* nomeJogadorItem = game->nomeJogador;

	while (nomeJogadorItem != NULL) {
		nome[i] = nomeJogadorItem->valor;
		nomeJogadorItem = nomeJogadorItem->proximo;
		i++;
	}

	snprintf(str,100, "USER : %s   Score: %d * %.2f = %d", nome, pontos, bonus, (int)(pontos * bonus));
}


void RenderInfoGame(SDL_Renderer* renderer, char* message) {

	TTF_Font* Font = TTF_OpenFont("fonts/VT323-Regular.ttf", 40);

	if (!Font) printf("Falha ao carregar a fonte: %s \nSDL2_ttf Error: %s\n", "fonts/VT323-Regular.ttf", TTF_GetError());

	SDL_Color White = { 255, 255, 255 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Font, message, White);

	SDL_Rect MessageRect;
	MessageRect.w = surfaceMessage->w;
	MessageRect.h = surfaceMessage->h;
	MessageRect.x = 20;
	MessageRect.y = 20;

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_RenderCopy(renderer, Message, NULL, &MessageRect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(Font);
}

void RenderMenuGame(SDL_Renderer* renderer, char menu[][20], int aux) {
	TTF_Font* Font = TTF_OpenFont("fonts/VT323-Regular.ttf", 60);

	if (!Font) printf("Falha ao carregar a fonte: %s \nSDL2_ttf Error: %s\n", "fonts/VT323-Regular.ttf", TTF_GetError());

	SDL_Color White = { 255, 255, 255 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Font, "SNAKE GAME", White);

	SDL_Rect MessageRect;
	MessageRect.w = surfaceMessage->w;
	MessageRect.h = surfaceMessage->h;
	MessageRect.x = 250;
	MessageRect.y = 150;

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_RenderCopy(renderer, Message, NULL, &MessageRect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	for (int i = 0; i < aux; i++) {
		surfaceMessage = TTF_RenderText_Solid(Font, menu[i], White);
		Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
		MessageRect.y += 100;
		SDL_RenderCopy(renderer, Message, NULL, &MessageRect);

		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);

	}

	TTF_CloseFont(Font);
}


void RenderParede(SDL_Renderer* renderer) {
	int xMin = 30, yMin = 100, xMax = 700, yMax = 730;
	int largura = 10, altura = 10;

	while (yMin < yMax) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_Rect rParedeEsq = {xMin, yMin, largura, altura};
		SDL_RenderFillRect(renderer, &rParedeEsq);
		SDL_RenderDrawRect(renderer, &rParedeEsq);

		SDL_Rect rParedeDir = { xMax, yMin, largura, altura };
		SDL_RenderFillRect(renderer, &rParedeDir);
		SDL_RenderDrawRect(renderer, &rParedeDir);
		yMin++;
	}

	yMin = 100;

	while (xMin < xMax) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_Rect rParedeCima = { xMin, yMin, largura, altura };
		SDL_RenderFillRect(renderer, &rParedeCima);
		SDL_RenderDrawRect(renderer, &rParedeCima);

		SDL_Rect rParedeBaixo = { xMin, yMax, largura, altura };
		SDL_RenderFillRect(renderer, &rParedeBaixo);
		SDL_RenderDrawRect(renderer, &rParedeBaixo);
		xMin++;
	}
}

void RenderJogador(Game* game, SDL_Renderer* renderer, char menu[][100], int aux, bool pipe) {
	TTF_Font* Font = TTF_OpenFont("fonts/VT323-Regular.ttf", 60);

	if (!Font) printf("Falha ao carregar a fonte: %s \nSDL2_ttf Error: %s\n", "fonts/VT323-Regular.ttf", TTF_GetError());

	SDL_Color White = { 255, 255, 255 };

	char message[20];

	char nome[12] = " ";
	int i = 0;
	Item* nomeJogadorItem = game->nomeJogador;

	while (nomeJogadorItem != NULL) {
		nome[i] = nomeJogadorItem->valor;
		nomeJogadorItem = nomeJogadorItem->proximo;
		i++;
	}

	snprintf(message, 20,"JOGADOR: %s%c", nome == " " ?  " " : nome, pipe == true ? '|' : ' ');

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Font, message, White);

	SDL_Rect MessageRect;
	MessageRect.w = surfaceMessage->w;
	MessageRect.h = surfaceMessage->h;
	MessageRect.x = 250;
	MessageRect.y = 200;

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_RenderCopy(renderer, Message, NULL, &MessageRect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	for (int i = 0; i < aux; i++) {
		surfaceMessage = TTF_RenderText_Solid(Font, menu[i], White);
		Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
		MessageRect.y += 100;
		SDL_RenderCopy(renderer, Message, NULL, &MessageRect);

		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);

	}

	TTF_CloseFont(Font);
}

void RunMainMenu(Game* game, SDL_Renderer* renderer) {
	TTF_Init();
	SDL_Event event;

	char mm[3][20] = { "1- NEW GAME", "2- SCORES", "3- QUIT GAME" };

	while (game->mainMenu) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		RenderMenuGame(renderer, mm, 3);

		SDL_RenderPresent(renderer); // Baseado nas alterações do renderizador modifica a tela

		while (SDL_PollEvent(&event)) {

			const Uint8* state = SDL_GetKeyboardState(NULL); // Grava a ultima tecla apertada no teclado

			if (state[SDL_SCANCODE_1]) {
				game->mainMenu = false;
				game->difMenu = true;
				break;
			}

			if (state[SDL_SCANCODE_2])  game->scores = true;

			if (state[SDL_SCANCODE_3] || event.type == SDL_QUIT) {
				game->mainMenu = false;
				game->status = false;
				break;
			}
		}
		SDL_Delay(70);
	}
}

void RunDifMenu(Game* game, SDL_Renderer* renderer) {
	TTF_Init();
	SDL_Event event;

	char dm[5][20] = { "1- FÁCIL", "2- MÉDIO", "3- DIFÍCIL", "4- VOLTAR", "5- QUIT GAME" };

	while (game->difMenu) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		RenderMenuGame(renderer, dm, 5);

		SDL_RenderPresent(renderer); // Baseado nas alterações do renderizador modifica a tela

		while (SDL_PollEvent(&event)) {

			const Uint8* state = SDL_GetKeyboardState(NULL); // Grava a ultima tecla apertada no teclado

			if (state[SDL_SCANCODE_1]) {
				game->cobra.velocidade = 10;
				game->tolerancia = 20;
				game->difMenu = false;
				game->jogador = true;
				break;
			}

			if (state[SDL_SCANCODE_2]) {
				game->cobra.velocidade = 15;
				game->tolerancia = 15;
				game->difMenu = false;
				game->jogador = true;
				break;
			}

			if (state[SDL_SCANCODE_3]) {
				game->cobra.velocidade = 18;
				game->tolerancia = 14;
				game->difMenu = false;
				game->jogador = true;
				break;
			}

			if (state[SDL_SCANCODE_4]) {
				game->mainMenu = true;
				game->difMenu = false;
				break;
			}

			if (state[SDL_SCANCODE_5] || event.type == SDL_QUIT) {
				game->status = false;
				game->difMenu = false;
				break;
			}
		}
		SDL_Delay(70);
	}
}

void RunJogador(Game* game, SDL_Renderer* renderer) {
	TTF_Init();
	SDL_Event event;

	game->nomeJogador = NULL;

	int i = 0;
	bool pipe = true;

	while (game->jogador)
	{

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		char jm[3][100] = {"1- JOGAR" , "2- VOLTAR", "3- MENU PRINCIPAL" };

		RenderJogador(game, renderer, jm, 3, pipe);

		pipe = !pipe;

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				game->jogador = false;
				game->status = false;
				break;
			}

			const Uint8* state = SDL_GetKeyboardState(NULL);

			if (i >= 3) {
				if (state[SDL_SCANCODE_1]) {
					game->jogador = false;
					Init(game);
					game->mainMenu = false;
					game->partida = true;
					break;
				}
			}

			if (state[SDL_SCANCODE_2]) {
				game->jogador = false;
				game->difMenu = true;
				break;
			}

			if (state[SDL_SCANCODE_3]) {
				game->jogador = false;
				game->mainMenu = true;
				break;
			}

			if (i >= 0) {
				if (state[SDL_SCANCODE_BACKSPACE]) {
					deletar(&game->nomeJogador, i);
					i--;
				}
			}

			if(i < 11){
				if (event.key.state == SDL_PRESSED && !state[SDL_SCANCODE_BACKSPACE] && !state[SDL_SCANCODE_1] && !state[SDL_SCANCODE_2] && !state[SDL_SCANCODE_3]) {
					adicionar(&game->nomeJogador, SDL_GetKeyName(event.key.keysym.sym)[0]);
					i++;
				}
			}

			RenderJogador(game, renderer, jm, 3, pipe);

			pipe = !pipe;

			SDL_RenderPresent(renderer);

		}
	}
	
}

void RunGame(Game* game, SDL_Renderer* renderer) 
{
	TTF_Init();
	SDL_Event event;
	while (game->partida)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		CobraMorte(game); // Verifica se a cobra morreu

		CobraCome(game); // Verifica se a cobra comeu

		CobraMovimento(game); // Arruma o movimento da cobra

		CobraAtualizacao(game, renderer); // Faz o movimento da cobra no renderizador

		ComidaAtualizacao(game, renderer); // Faz a alteração da posição da comida no renderizador

		char str[100];
		InfoGame(game,str);
		
		RenderInfoGame(renderer, str);// Criar uma função para gerar a string de informações

		RenderParede(renderer);

		SDL_RenderPresent(renderer); // Baseado nas alterações do renderizador modifica a tela

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) {
				game->status = false;
				break;
			}

			const Uint8* state = SDL_GetKeyboardState(NULL); // Grava a ultima tecla apertada no teclado

			if (state[SDL_SCANCODE_ESCAPE]) {
				game->partida = false;
				game->auxMenu = true;
				break;
			}

			if (state[SDL_SCANCODE_UP] && game->cobra.direcao != BAIXO)  game->cobra.direcao = CIMA;

			if (state[SDL_SCANCODE_DOWN] && game->cobra.direcao != CIMA)  game->cobra.direcao = BAIXO;

			if (state[SDL_SCANCODE_RIGHT] && game->cobra.direcao != ESQUERDA)  game->cobra.direcao = DIREITA;

			if (state[SDL_SCANCODE_LEFT] && game->cobra.direcao != DIREITA)  game->cobra.direcao = ESQUERDA;
		}
		SDL_Delay(100);
	}
}


void RunAuxMenu(Game* game, SDL_Renderer* renderer) {

	TTF_Init();
	SDL_Event event;
	while (game->auxMenu) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		char am[4][20] = { "1- MAIN MENU", "2- NEW GAME", "3- RESUME GAME", "4- QUIT GAME" };

		RenderMenuGame(renderer, am, 4);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {

			const Uint8* state = SDL_GetKeyboardState(NULL);

			if (state[SDL_SCANCODE_1]) {
				game->mainMenu = true;
				game->auxMenu = false;
				break;
			}

			if (state[SDL_SCANCODE_2]) {
				Init(game);
				game->auxMenu = false;
				game->difMenu = true;
				break;
			}

			if (state[SDL_SCANCODE_3]) {
				game->auxMenu = false;
				game->partida = true;
				break;
			}

			if (state[SDL_SCANCODE_4] || event.type == SDL_QUIT) {
				game->status = false;
				game->auxMenu = false;
				break;
			}
		}
		SDL_Delay(100);
	}

}