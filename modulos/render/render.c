#include <stdio.h>
#include <raylib.h>
#include "tipos/tipos.h"
#include "constantes/constantes.h"

void desenhar_mapa(char map[MAPA_LINHAS][MAPA_LINHAS]) { // desenhar o mapa com base na matriz do mapa
    int lin = MAPA_LINHAS;
    int col = MAPA_COLUNAS;
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

void desenhar_jogador(Vector2 pos, int altura, int largura) {
    DrawRectangle(pos.x, pos.y, altura, largura, RED);
}

void desenhar_jogo(Jogo jogo) {
    ClearBackground(DARKGREEN);
    desenhar_mapa(jogo.mapa);
    desenhar_jogador(jogo.jogador.pos, TAMANHO_PERSONAGEM, TAMANHO_PERSONAGEM);
}
