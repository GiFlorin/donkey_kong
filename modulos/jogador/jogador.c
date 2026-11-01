/*modulo para movimentação e ações do jogador*/

#include "jogador.h"
#include "tipos/tipos.h"
#include "constantes/constantes.h"
#include <raylib.h>
#include <stdio.h>
#include <math.h>

int mover_jogador(int dir, Jogador * jogador) { // 1 em sucesso, 0 se nao puder mover
    float delta = GetFrameTime(); 
    float dist = (VELOCIDADE_JOGADOR * delta);
    float nova_pos = (jogador->pos).x + dist * dir;

    // se estiver na borda do mapa
    // if (linha_pes < 0 || linha_pes >= MAPA_LINHAS) return 0; 
    if (nova_pos < 0) return 0;
    else if (nova_pos + TAMANHO_PERSONAGEM >= GetScreenWidth()) return 0;
    else (jogador->pos).x = nova_pos;
    return 1;
    
}

int jogador_esta_no_chao(Vector2 pos_jogador, char mapa[MAPA_LINHAS][MAPA_COLUNAS]) { // 1 se estiver no chao e 0 se nao
    float delta_col = (float)GetScreenWidth() / MAPA_COLUNAS;
    float delta_lin = (float)GetScreenHeight() / MAPA_LINHAS;

    int col_esq = floor(pos_jogador.x/delta_col); // em qual coluna o extremo esquerdo do personagem está
    int col_dir = ceil(pos_jogador.x/delta_col); // em qual coluna o extremo direito do personagem está

    int linha_pes = (int)(pos_jogador.y + TAMANHO_PERSONAGEM)/delta_lin; // em qual linha os pes do personagem estao

    // se estiver na borda do mapa
    if (linha_pes < 0 || linha_pes >= MAPA_LINHAS) return 0; 
    if (col_esq < 0) col_esq = 0;
    if (col_dir >= MAPA_COLUNAS) col_dir = MAPA_COLUNAS - 1;

    if (mapa[linha_pes][col_esq] == PLATAFORMAS || mapa[linha_pes][col_dir] == PLATAFORMAS) { // so o bloco de baixo for chao
        return 1;
    }
    else if(mapa[linha_pes][col_esq] == ESCADA || mapa[linha_pes][col_dir] == ESCADA) { // se embaixo dele tiver uma escada
        if (jogador_esta_na_escada(pos_jogador, mapa) == 2) // se atras dele tem a descida de uma escada
            return 1;
    }

    return 0;
}

void jogador_pula(Jogo * jogo) {
    // se o jogador estiver no chao ou na saida da escada
    if (jogador_esta_no_chao((jogo->jogador).pos, jogo->mapa)) {
        (jogo->jogador).vel_y = -PULO_JOGADOR;
    }
}

void jogador_atualizar_pos_y(Jogo * jogo) {
    float delta = GetFrameTime();

    // aplica gravidade e move
    if (!jogador_esta_no_chao((jogo->jogador).pos, jogo->mapa))
        (jogo->jogador).vel_y += GRAVIDADE * delta;

    (jogo->jogador).pos.y += (jogo->jogador).vel_y * delta;
    
    // se o jogador estiver na escada
    if ((jogador_esta_na_escada(jogo->jogador.pos, jogo->mapa) == 1) || (jogador_esta_na_escada(jogo->jogador.pos, jogo->mapa) == 3) )
        (jogo->jogador).vel_y = 0;

    // se está descendo e tocou no chao
    if (((jogo->jogador).vel_y > 0) && jogador_esta_no_chao((jogo->jogador).pos, jogo->mapa)) {
        float tile_h = (float)GetScreenHeight() / MAPA_LINHAS;
        int lin_pes = (int)(((jogo->jogador).pos.y + TAMANHO_PERSONAGEM) / tile_h);
        (jogo->jogador).vel_y = 0;
    }
}

int jogador_esta_na_escada(Vector2 pos, char mapa[MAPA_LINHAS][MAPA_COLUNAS]) { 
    /*0 se nao, 1 se tem escada atras do jogador e 2 se ele esta na saida da escada e 3 se ele esta da subida da escada*/
    float delta_col = (float)GetScreenWidth() / MAPA_COLUNAS;
    float delta_lin = (float)GetScreenHeight() / MAPA_LINHAS;

    int linhas[2], colunas[2]; // as 2 linhas e colunas que o personagem ocupa

    colunas[0] = floor(pos.x/delta_col); // em qual coluna o extremo esquerdo do personagem está
    colunas[1] = ceil((pos.x)/delta_col); // em qual coluna o extremo direito do personagem está

    linhas[0] = floor((pos.y)/delta_lin); // em qual linha os pes do personagem estao
    linhas[1] = ceil((pos.y)/delta_lin);

    for(int i = 0; i < 2; i++) { // itera pelas 2 linhas
        for(int j = 0; j < 2; j++) { // itera pelas 2 colunas
            if (mapa[linhas[i]][colunas[j]] == ESCADA)
                return 1;
            else if (mapa[linhas[i]][colunas[j]] == DESCIDA_ESCADA)
                return 2;
            else if((mapa[linhas[i]][colunas[j]] == SUBIDA_ESCADA))
                return 3;
            
        }
    }
    return 0;
}

void movimento_escada(int dir, Vector2 * pos_jogador, int esta_na_escada) {
    float delta = GetFrameTime(); 
    float dist = (VELOCIDADE_JOGADOR * delta);
    int pode_ir = 0;

    if (esta_na_escada == 1) { // se ele esta na escada, pode ir para cima e para baixo
        pode_ir = 1;
        }
    else if (esta_na_escada == 2) {// se ele esta na descida da escada, so pode descer
        if (dir == -1)  {
            pode_ir = 1;
        }
    }
    else if (esta_na_escada == 3) {// se ele esta na subida da escada, so pode subir
        if (dir == 1) {
            pode_ir = 1;
        }
    }
    if (pode_ir)
        pos_jogador->y += dist * -dir;
}
