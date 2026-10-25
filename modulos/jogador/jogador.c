#include "jogador.h"
#include "tipos/tipos.h"
#include <raylib.h>

void mover_jogador(int dir, Jogador * jogador) {
    float delta = GetFrameTime(); 
    float dist = (VELOCIDADE_JOGADOR * delta);

    (jogador->pos).x += dist * dir;

}
