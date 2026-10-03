#include <raylib.h>
#include <stdio.h>

#define TAM 32 // tamanho personagem
#define VEL 200

#define LINHAS 30
#define COLUNAS 30
#define TAMBLOCO 32 // render 32 bits

int main(void)
{
    // DECLARACAO VARIAVEIS
    char mapa[LINHAS][COLUNAS + 1] = {
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
    "    H                      H  ", 
    "PZZZSZZZZZZZZZEZZZZZZZZZZZZHZZ", 
    "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"  };
    
    // SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(TAMBLOCO * LINHAS, TAMBLOCO * COLUNAS, "Donkey Kong");
    float pos[2] = {GetScreenWidth()/2, GetScreenHeight()/2};

    
    
    while (!WindowShouldClose())
    {

        // movimento do personagem
        float delta = GetFrameTime(); 
        float move = (VEL * delta);

        if (IsKeyDown(KEY_A)) pos[0] -= move;
        else if (IsKeyDown(KEY_D)) pos[0] += move;
        if (IsKeyDown(KEY_W)) pos[1] -= move;
        else if (IsKeyDown(KEY_S)) pos[1] += move;

        // DRAWING
        BeginDrawing();
        ClearBackground(DARKGREEN);
        DrawRectangle(pos[0], pos[1], TAM, TAM, RED);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}