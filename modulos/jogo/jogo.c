#include <stdio.h>
#include "tipos/tipos.h"
#include "jogador/jogador.h"
#include <raylib.h>

void atualizar_jogo(Jogo * jogo) {
    jogo->tempo += GetFrameTime();
    // Input mover personagem
    if (IsKeyDown(KEY_A)) 
        mover_jogador(-1, &jogo->jogador);

    else if (IsKeyDown(KEY_D)) 
        mover_jogador(1, &jogo->jogador);
}
