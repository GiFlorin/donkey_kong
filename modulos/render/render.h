#ifndef RENDER_H
#define RENDER_H
#include <raylib.h>
#include "tipos/tipos.h"
#include "constantes/constantes.h"

void desenhar_mapa(char map[MAPA_LINHAS][MAPA_COLUNAS]); // desenhar o mapa com base na matriz do mapa

void desenhar_jogador(Vector2 pos, int altura, int largura);

void desenhar_jogo(Jogo jogo);

#endif