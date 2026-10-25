#include <raylib.h>
#include <stdio.h>

// modulos locais
#include "mapa/mapa.h"
#include "constantes/constantes.h"
#include "render/render.h"
#include "tipos/tipos.h"
#include "jogo/jogo.h"

int main(void)
{
    // DECLARACAO VARIAVEIS
    Jogo jogo = {0};
    ler_arquivo(MAPA_LINHAS, MAPA_COLUNAS, jogo.mapa);
    
    
    // inicializar tela
    InitWindow(ALTURA_JANELA, LARGURA_JANELA, "Donkey Kong");
    SetTargetFPS(FPS_ALVO);
    jogo.jogador.pos = player_spawn_pos(MAPA_LINHAS, MAPA_COLUNAS, jogo.mapa);

    while (!WindowShouldClose())
    {
        // atualizar o jogo
        atualizar_jogo(&jogo);

        // DRAWING
        desenhar_jogo(jogo);
    }
    
    CloseWindow();
    return 0;
}
