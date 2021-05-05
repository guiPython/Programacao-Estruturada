#ifndef FOOD
#define FOOD

#define LARGURA_COMIDA 20
#define COMPRIMENTO_COMIDA 20

#include <SDL.h>
#include "game.h"

void ComidaAtualizacao(Game* game,SDL_Renderer* renderer);

void ComidaSetPosicao(Comida* comida);

#endif 
