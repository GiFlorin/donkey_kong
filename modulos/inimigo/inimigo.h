#ifndef INIMIGO_H
#define INIMIGO_H

#include "inimigo.h"
#include <raylib.h>
#include "constantes/constantes.h"
#include <math.h>
#include "tipos/tipos.h"

void movimento_inimigos(char mapa[MAPA_LINHAS][MAPA_COLUNAS], Inimigo inimigos[MAX_INIMIGOS], int n_inimigos);

int inimigo_esta_na_borda(Vector2 pos, char mapa[MAPA_LINHAS][MAPA_COLUNAS]);

void andar_inimigo(Inimigo * inimigo);

int inimigo_colide_jogador(Vector2 pos_jogador, Inimigo inimigos[MAX_INIMIGOS], int n_inimigos);

#endif