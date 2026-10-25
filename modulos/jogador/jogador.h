#ifndef JOGADOR_H
#define JOGADOR_H
#include "tipos/tipos.h"
#include "constantes/constantes.h"
#include <raylib.h>

void mover_jogador(int dir, Jogador * jogador);

int jogador_esta_no_chao(Vector2 pos_player, char mapa[MAPA_LINHAS][MAPA_COLUNAS]); // verifica se o jogador está no chao

#endif