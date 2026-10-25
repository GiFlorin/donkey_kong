#ifndef TIPOS_H
#define TIPOS_H

#include "constantes/constantes.h"
#include <raylib.h>

// ENUMS
typedef enum {
    TELA_MENU, 
    TELA_JOGANDO, 
    TELA_PAUSA,
    TELA_RANKING, 
    TELA_FIM, 
    TELA_NOME, 
    TELA_SAIR
} EstadoTela;

typedef enum { ESQUERDA = -1, DIREITA = 1 } Direcao;

// STRUCTS

typedef struct { // struct jogador
    Vector2 pos;
    int     ativo;        // 1 = vivo, 0 = morto
} Jogador;

typedef struct {
    char mapa[MAPA_LINHAS][MAPA_COLUNAS];
    double tempo;
    Jogador jogador;

} Jogo;

#endif