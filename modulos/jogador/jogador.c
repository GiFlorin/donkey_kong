#include "jogador.h"
#include "tipos/tipos.h"
#include "constantes/constantes.h"
#include <raylib.h>
#include <stdio.h>
#include <math.h>

void mover_jogador(int dir, Jogador * jogador) {
    float delta = GetFrameTime(); 
    float dist = (VELOCIDADE_JOGADOR * delta);

    (jogador->pos).x += dist * dir;
    
}

int jogador_esta_no_chao(Vector2 pos_jogador, char mapa[MAPA_LINHAS][MAPA_COLUNAS]) { // 1 se estiver no chao e 0 se nao
    float delta_col = (float)GetScreenWidth() / MAPA_COLUNAS;
    float delta_lin = (float)GetScreenHeight() / MAPA_LINHAS;

    int col_esq = floor(pos_jogador.x/delta_col); // em qual coluna o extremo esquerdo do personagem está
    int col_dir = ceil((pos_jogador.x + 1)/delta_col); // em qual coluna o extremo direito do personagem está

    int linha_pes = (int)(pos_jogador.y + TAMANHO_PERSONAGEM)/delta_lin; // em qual linha os pes do personagem estao

    // se estiver na borda do mapa
    if (linha_pes < 0 || linha_pes >= MAPA_LINHAS) return 0; 
    if (col_esq < 0) col_esq = 0;
    if (col_dir >= MAPA_COLUNAS) col_dir = MAPA_COLUNAS - 1;

    if (mapa[linha_pes][col_esq] == 'Z' || mapa[linha_pes][col_dir] == 'Z') { // so o bloco de baixo for chao
        return 1;
    }

    return 0;
}

void jogador_pula(Jogo * jogo) {
    if (jogador_esta_no_chao((jogo->jogador).pos, jogo->mapa)) {
        (jogo->jogador).vel_y = -PULO_JOGADOR;
    }
}

void jogador_atualizar_pos_y(Jogo * jogo) {
    float delta = GetFrameTime();

    // aplica gravidade e move
    (jogo->jogador).vel_y += GRAVIDADE * delta;
    (jogo->jogador).pos.y += (jogo->jogador).vel_y * delta;

    // se está descendo e tocou no chao
    if (((jogo->jogador).vel_y > 0) && jogador_esta_no_chao((jogo->jogador).pos, jogo->mapa)) {
        float tile_h = (float)GetScreenHeight() / MAPA_LINHAS;
        int lin_pes = (int)(((jogo->jogador).pos.y + TAMANHO_PERSONAGEM) / tile_h);
        (jogo->jogador).pos.y = lin_pes * tile_h - TAMANHO_PERSONAGEM;   // encosta no chão
        (jogo->jogador).vel_y = 0;
    }

}
