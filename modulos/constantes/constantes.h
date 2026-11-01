#ifndef CONSTANTES_H
#define CONSTANTES_H

#define MAPA_LINHAS      30
#define MAPA_COLUNAS     30
#define TAMANHO_BLOCO    32
#define TAMANHO_PERSONAGEM 32
#define TAMANHO_INIMIGO   32
#define LARGURA_JANELA   (MAPA_COLUNAS * TAMANHO_BLOCO)
#define ALTURA_JANELA    (MAPA_LINHAS * TAMANHO_BLOCO)
#define FPS_ALVO         60
#define VELOCIDADE_JOGADOR 130
#define PULO_JOGADOR     150
#define GRAVIDADE        270
#define VELOCIDADE_INIMIGO 100
#define MAX_INIMIGOS     20
#define MAX_CAMINHO      50
#define MAX_PLACAR       10
#define TAM_NOME         20
#define TAM_FONTE        30

#define POS_INI_JOGADOR 'P'
#define INIMIGOS 'E'
#define PLATAFORMAS 'Z'
#define PORTA 'F'
#define SUBIDA_ESCADA 'S'
#define DESCIDA_ESCADA 'D'
#define ESCADA 'H'

#endif