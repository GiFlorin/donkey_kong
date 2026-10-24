#include <raylib.h>
#include <stdio.h>

// modulos
#include "modulos/mapa/mapa.h"
#include "modulos/constantes/constantes.h"

#define TAM 32 // tamanho personagem
#define VEL 300

// HEADER
void desenhar_mapa(int lin, int col, char map[lin][col]);
Vector2 player_spawn_pos(int lin, int col, char map[lin][col]);

// Structures
struct character { // estrutura do personagem
    Vector2 pos;
};

int main(void)
{
    // DECLARACAO VARIAVEIS
    /*char mapa[LINHAS][COLUNAS + 1] = {
    "                              ", 
    "           ZZZFZZZ            ", 
    "              H               ", 
    "              H               ", 
    "    ZZZZZZZZZZSZZZZZZZZZ      ", 
    "    D                  H      ", 
    "    H                  H      ", 
    "    H                  H      ", 
    "    ZZZZZZZZSEZZZZZZZZZSZZZZ  ", 
    "            H              D  ", 
    "            H              H  ", 
    "            H              H  ", 
    "  ZZZZZZZZZZSZZZZZEZZZZZZZZH  ", 
    "  D                        H  ", 
    "  H                        H  ", 
    "  H                        H  ", 
    "  ZZZZZZZZZZZZZZZZSZZZZZZZZH  ", 
    "                  H        D  ", 
    "                  H        H  ", 
    "                  H        H  ", 
    "    ZZZZEZZZZZZZZZSZZZZZZZZH  ", 
    "    D                      H  ", 
    "    H                      H  ", 
    "    H                      H  ", 
    "ZZZZSZZZZZZZZZZZZZZZZZZZZZZHZZ", 
    "    H                      D  ", 
    "    H                      H  ", 
    " P  H                      H  ", 
    "ZZZZSZZZZZZZZZEZZZZZZZZZZZZHZZ", 
    "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"  };*/
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
void desenhar_mapa(int lin, int col, char map[lin][col]) { // desenhar o mapa
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    for(int l = 0; l < lin; l++) {
        for(int c = 0; c < col; c++) {
            int x0 = c * w / col;
            int y0 = l * h / lin;

            int x1 = (c + 1) * w / col;
            int y1 = (l + 1) * h / lin;

            if (map[l][c] == 'Z')
                DrawRectangle(x0, y0, (x1 - x0), (y1 - y0), PINK);
            else if (map[l][c] == 'H' || map[l][c] == 'D' || map[l][c] == 'S')
                DrawRectangle(x0, y0, (x1 - x0), (y1 - y0), SKYBLUE);
        }
    }
}

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
