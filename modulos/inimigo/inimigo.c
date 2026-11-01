/*Módulo para movimento e ações de inimigos*/

#include "inimigo.h"
#include "tipos/tipos.h"
#include <raylib.h>
#include "constantes/constantes.h"
#include <math.h>

void movimento_inimigos(char mapa[MAPA_LINHAS][MAPA_COLUNAS], Inimigo inimigos[MAX_INIMIGOS], int n_inimigos) {
    
    for (int i = 0; i < n_inimigos; i++) { // itera por todos os inimigos do vetor
        // se estiver na borda da plataforma, mudar de direcao
        if (inimigo_esta_na_borda(inimigos[i].pos, mapa)) {
            inimigos[i].dir *= -1;
        }

        // andar
        andar_inimigo(&inimigos[i]);
    }
}

int inimigo_esta_na_borda(Vector2 pos, char mapa[MAPA_LINHAS][MAPA_COLUNAS]) { // 1 se esta na borda da plataforma e 0 se nao
    float delta_col = (float)GetScreenWidth() / MAPA_COLUNAS;
    float delta_lin = (float)GetScreenHeight() / MAPA_LINHAS;

    int col_esq = floor(pos.x/delta_col); // 1 coluna pra esquerda do inimigp
    int col_dir = ceil(pos.x/delta_col);  // 1 coluna pra direita do inimigo

    int linha_pes = (int)(pos.y + TAMANHO_PERSONAGEM)/delta_lin; // em qual linha os pes do personagem estao

    // se estiver na borda do mapa
    if (linha_pes < 0 || linha_pes >= MAPA_LINHAS) return 1; 
    if (col_esq < 0) return 1;
    if (col_dir >= MAPA_COLUNAS) return 1;

    if (((mapa[linha_pes][col_esq] == PLATAFORMAS) || (mapa[linha_pes][col_esq] == ESCADA)) 
        && ((mapa[linha_pes][col_dir] == PLATAFORMAS) || (mapa[linha_pes][col_dir] == ESCADA))) { // so o bloco de baixo for chao ou escada
        return 0;
    }

    return 1;
}

void andar_inimigo(Inimigo * inimigo) {
    float delta = GetFrameTime();
    if (inimigo->vivo == 1) {
        inimigo->pos.x += VELOCIDADE_INIMIGO * delta * inimigo->dir;
    }
}
