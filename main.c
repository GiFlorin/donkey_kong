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
    char caminho[MAX_CAMINHO] = "maps/mapa1.txt";
    
    // inicializar tela
    InitWindow(ALTURA_JANELA, LARGURA_JANELA, "Donkey Kong");
    SetTargetFPS(FPS_ALVO);

    // Carregar nivel
    carregar_nivel(&jogo, caminho);

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
