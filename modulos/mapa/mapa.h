#ifndef MAPA_H
#define MAPA_H
#include <raylib.h>

int ler_arquivo(int lin, int col, char destino[lin][col]);

Vector2 player_spawn_pos(int lin, int col, char map[lin][col]);

#endif