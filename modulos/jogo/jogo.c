#include <stdio.h>
#include "tipos/tipos.h"
#include "jogador/jogador.h"
#include <raylib.h>

void atualizar_jogo(Jogo * jogo) {
    // atualiza a contagem de tempo
    jogo->tempo += GetFrameTime(); // get frame time = o tempo (em s) desde o ultimo frame

    // Input mover personagem
    if (IsKeyDown(KEY_A)) 
        mover_jogador(-1, &jogo->jogador);

    else if (IsKeyDown(KEY_D)) 
        mover_jogador(1, &jogo->jogador);
    // Input pular
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE))
        printf("%d", jogador_esta_no_chao((jogo->jogador).pos, jogo->mapa));

}
