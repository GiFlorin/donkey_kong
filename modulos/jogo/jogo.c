#include <stdio.h>
#include "jogo.h"
#include "tipos/tipos.h"
#include "jogador/jogador.h"
#include "inimigo/inimigo.h"
#include "mapa/mapa.h"
#include "ui/ui.h"
#include <raylib.h>

void inicializar_jogo(Ambiente * ambiente) {
    if (ambiente->estado_tela != TELA_JOGANDO) {
        ambiente->estado_tela = TELA_JOGANDO;
        printf("Entrando no jogo\n");
    // Carregar nivel
    carregar_nivel(&ambiente->jogo);
    }
}

void atualizar_jogo(Ambiente * ambiente) {
    Jogo *jogo = &ambiente->jogo;
    //  atualiza a contagem de tempo
    jogo->tempo += GetFrameTime(); // get frame time = o tempo (em s) desde o ultimo frame
    jogador_atualizar_pos_y(jogo);
    movimento_inimigos(jogo->mapa, jogo->inimigos, jogo->n_inimigos);

    // checar se o jogador esta colidindo com o inimigo
    if (inimigo_colide_jogador(jogo->jogador.pos, jogo->inimigos, jogo->n_inimigos)) {
        printf("MORREU\n");
        tela_perdeu(ambiente);
    }
        

    // Input mover personagem
    if (IsKeyDown(KEY_A)) 
        mover_jogador(-1, &jogo->jogador);

    else if (IsKeyDown(KEY_D)) 
        mover_jogador(1, &jogo->jogador);

    // Input pular
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) {
        movimento_escada(1, &(jogo->jogador.pos), jogador_esta_na_escada(jogo->jogador.pos, jogo->mapa));
        if (!jogador_esta_na_escada(jogo->jogador.pos, jogo->mapa) || (jogador_esta_na_escada(jogo->jogador.pos, jogo->mapa) == 2)) // TODO consertar isso
            jogador_pula(jogo);
        
    }
    else if (IsKeyDown(KEY_S)) 
        movimento_escada(-1, &(jogo->jogador.pos), jogador_esta_na_escada(jogo->jogador.pos, jogo->mapa));
    
}
