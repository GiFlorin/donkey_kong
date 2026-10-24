#include <raylib.h>
#include <stdio.h>

// modulos
#include "modulos/mapa/mapa.h"
#include "modulos/constantes/constantes.h"
#include "modulos/render/render.h"

#define TAM 32 // tamanho personagem
#define VEL 300

// HEADER
Vector2 player_spawn_pos(int lin, int col, char map[lin][col]);

// Structures
struct character { // estrutura do personagem
    Vector2 pos;
};

int main(void)
{
    // DECLARACAO VARIAVEIS
    char mapa[MAPA_LINHAS][MAPA_COLUNAS + 1] = {0};
    ler_arquivo(MAPA_LINHAS, MAPA_COLUNAS + 1, mapa);
    
    // inicializar tela
    InitWindow(TAMANHO_BLOCO * MAPA_LINHAS, TAMANHO_BLOCO * MAPA_COLUNAS, "Donkey Kong");
    SetTargetFPS(FPS_ALVO);

    struct character player;
    player.pos = player_spawn_pos(MAPA_LINHAS, MAPA_COLUNAS, mapa);
    printf("[%d, %d]", (int)player.pos.x, (int)player.pos.y);

    while (!WindowShouldClose())
    {

        // movimento do personagem
        float delta = GetFrameTime(); 
        float move = (VELOCIDADE_JOGADOR * delta);

        if (IsKeyDown(KEY_A)) player.pos.x -= move;
        else if (IsKeyDown(KEY_D)) player.pos.x += move;

        // DRAWING
        BeginDrawing();
        ClearBackground(DARKGREEN);
        desenhar_mapa(MAPA_LINHAS, MAPA_COLUNAS + 1, mapa);
        DrawRectangle(player.pos.x, player.pos.y, TAM, TAM, RED);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}

// FUNCOES

Vector2 player_spawn_pos(int lin, int col, char map[lin][col]) { // encontrar a posicao inicial do personagem
    Vector2 pos = {0, 0};
    for(int l = 0; l < lin; l++) {

        for(int c = 0; c < col; c++) {
            if (map[l][c] == 'P') {
                pos.x = (GetScreenWidth()/col) * c;
                pos.y = (GetScreenHeight()/lin) * l;
            }
        }
    }
    return pos;
}
