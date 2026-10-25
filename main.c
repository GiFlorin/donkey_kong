#include <raylib.h>
#include <stdio.h>

// modulos
#include "mapa/mapa.h"
#include "constantes/constantes.h"
#include "render/render.h"
#include "tipos/tipos.h"

int main(void)
{
    // DECLARACAO VARIAVEIS
    Jogo jogo = {0};
    ler_arquivo(MAPA_LINHAS, MAPA_COLUNAS, jogo.mapa);
    
    
    // inicializar tela
    InitWindow(TAMANHO_BLOCO * MAPA_LINHAS, TAMANHO_BLOCO * MAPA_COLUNAS, "Donkey Kong");
    SetTargetFPS(FPS_ALVO);

    
    jogo.jogador.pos = player_spawn_pos(MAPA_LINHAS, MAPA_COLUNAS, jogo.mapa);

    while (!WindowShouldClose())
    {
        // movimento do personagem
        float delta = GetFrameTime(); 
        float dist = (VELOCIDADE_JOGADOR * delta);

        if (IsKeyDown(KEY_A)) jogo.jogador.pos.x -= dist;
        else if (IsKeyDown(KEY_D)) jogo.jogador.pos.x += dist;

        // DRAWING
        desenhar_jogo(jogo);
    }
    
    CloseWindow();
    return 0;
}
