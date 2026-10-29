#ifndef JOGADOR_H
#define JOGADOR_H
#include "tipos/tipos.h"
#include "constantes/constantes.h"
#include <raylib.h>

void mover_jogador(int dir, Jogador * jogador);

int jogador_esta_no_chao(Vector2 pos_player, char mapa[MAPA_LINHAS][MAPA_COLUNAS]); // verifica se o jogador está no chao

void jogador_pula(Jogo * jogo);

void jogador_atualizar_pos_y(Jogo * jogo);

int jogador_esta_na_escada(Vector2 pos, char mapa[MAPA_LINHAS][MAPA_COLUNAS]); // checa se o jogador esta na escada

#endif