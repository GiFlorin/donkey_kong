#include <stdio.h>
#include "jogo.h"
#include "tipos/tipos.h"
#include "jogador/jogador.h"
#include <raylib.h>

void atualizar_jogo(Jogo * jogo) {
    //  atualiza a contagem de tempo
    jogo->tempo += GetFrameTime(); // get frame time = o tempo (em s) desde o ultimo frame
    jogador_atualizar_pos_y(jogo);

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
