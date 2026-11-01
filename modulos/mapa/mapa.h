#ifndef MAPA_H
#define MAPA_H
#include <raylib.h>
#include "constantes/constantes.h"
#include "tipos/tipos.h"

void carregar_nivel(Jogo * jogo, char caminho[MAX_CAMINHO]);

int ler_arquivo(int lin, int col, char caminho[MAX_CAMINHO], char destino[lin][col]);

Vector2 player_spawn_pos(int lin, int col, char map[lin][col]);

#endif