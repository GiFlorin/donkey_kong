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
    Vector2 pos;          // posiçao no raylib é ancorada no ponto superior esquerdo
    float   vel_y;        // velocidade vertical do jogador
    int     ativo;        // 1 = vivo, 0 = morto
} Jogador;

typedef struct {
    Vector2 pos;         // posicao
    int dir;             // direcao que ele esta andando atualmente
    int vivo;            // se ele esta vivo ou nao
} Inimigo;

typedef struct {
    char mapa[MAPA_LINHAS][MAPA_COLUNAS];  // matriz do mapa
    Inimigo inimigos[MAX_INIMIGOS];        // vetor com todos os inimigos do mapa
    float tempo;                           // cronometro do nivel
    Jogador jogador;                       // dados do jogador
    int fase_num;

} Jogo;

#endif