/*Módulo para movimento e ações de inimigos*/

#include "inimigo.h"
#include "tipos/tipos.h"
#include <raylib.h>
#include "constantes/constantes.h"
#include <math.h>

int inimigo_esta_no_chao(Vector2 pos, char mapa[MAPA_LINHAS][MAPA_COLUNAS]) { // 1 se estiver no chao e 0 se nao
    float delta_col = (float)GetScreenWidth() / MAPA_COLUNAS;
    float delta_lin = (float)GetScreenHeight() / MAPA_LINHAS;

    int col_esq = floor(pos.x/delta_col); // em qual coluna o extremo esquerdo do personagem está
    int col_dir = ceil(pos.x/delta_col); // em qual coluna o extremo direito do personagem está

    int linha_pes = (int)(pos.y + TAMANHO_PERSONAGEM)/delta_lin; // em qual linha os pes do personagem estao

    // se estiver na borda do mapa
    if (linha_pes < 0 || linha_pes >= MAPA_LINHAS) return 0; 
    if (col_esq < 0) col_esq = 0;
    if (col_dir >= MAPA_COLUNAS) col_dir = MAPA_COLUNAS - 1;

    if (mapa[linha_pes][col_esq] == PLATAFORMAS || mapa[linha_pes][col_dir] == PLATAFORMAS) { // so o bloco de baixo for chao
        return 1;
    }
    else if(mapa[linha_pes][col_esq] == ESCADA || mapa[linha_pes][col_dir] == ESCADA) { // se embaixo dele tiver uma escada
        return 1;
    }

    return 0;
}

void movimento_inimigos(char mapa[MAPA_LINHAS][MAPA_COLUNAS], Inimigo inimigos[MAX_INIMIGOS], int n_inimigos) {
    
    for (int i = 0; i < n_inimigos; i++) { // itera por todos os inimigos do vetor
        // TODO: se estiver na borda da plataforma, mudar de direcao
        andar_inimigo(&inimigos[i]);
    }
}

void andar_inimigo(Inimigo * inimigo) {
    float delta = GetFrameTime();
    if (inimigo->vivo == 1) {
        inimigo->pos.x += VELOCIDADE_INIMIGO * delta * inimigo->dir;
    }
}
