#ifndef MAPA_H
#define MAPA_H
#include <raylib.h>
#include "constantes/constantes.h"
#include "tipos/tipos.h"

void carregar_nivel(Jogo * jogo);

int ler_arquivo(int lin, int col, char caminho[MAX_CAMINHO], char destino[lin][col]);

Vector2 player_spawn_pos(int lin, int col, char map[lin][col]);

int carregar_inimigos(char mapa[MAPA_LINHAS][MAPA_COLUNAS], Inimigo inimigos[MAX_INIMIGOS]);

#endif