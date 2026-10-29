#include <stdio.h>
#include "tipos/tipos.h"
#include "jogador/jogador.h"
#include <raylib.h>

void atualizar_jogo(Jogo * jogo) {
    // atualiza a contagem de tempo
    jogo->tempo += GetFrameTime(); // get frame time = o tempo (em s) desde o ultimo frame
    jogador_atualizar_pos_y(jogo);

    // Input mover personagem
    if (IsKeyDown(KEY_A)) 
        mover_jogador(-1, &jogo->jogador);

    else if (IsKeyDown(KEY_D)) 
        mover_jogador(1, &jogo->jogador);

    // Input pular
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) {
        jogador_pula(jogo);
        printf("\nJogador esta na escada: %d \n", jogador_esta_na_escada(jogo->jogador.pos, jogo->mapa));
    }

}
