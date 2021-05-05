#ifndef SNAKE
#define SNAKE

#define CIMA 1
#define BAIXO 2
#define ESQUERDA 3
#define  DIREITA 4

#include <stdbool.h>
#include <stdlib.h>
#include <SDL.h>
#include "game.h"

void setupCobra(Cobra* cobra);

int CobraTamanho(Game* game);

bool CobraColisao(Game game);

void CobraMorte(Game* game, FILE* file);

void CobraCome(Game* game);

void CobraAtualizacao(Game* game,SDL_Renderer* renderer);

void CobraMovimento(Game* game);

double DistanciaCobraComida(Game* game);

double DistanciaCobra(Game* game, int i);

#endif