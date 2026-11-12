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

            if (map[l][c] == PLATAFORMAS) // chao
                DrawRectangle(x0, y0, (x1 - x0), (y1 - y0), PINK);
            else if (map[l][c] == ESCADA || map[l][c] == SUBIDA_ESCADA) // escada
                DrawRectangle(x0, y0, (x1 - x0), (y1 - y0), SKYBLUE);
            else if(map[l][c] == PORTA) // porta
                DrawRectangle(x0, y0, (x1 - x0), (y1 - y0), ORANGE);
        }
    }
}

void desenhar_jogador(Vector2 pos, int altura, int largura) {
    DrawRectangle(pos.x, pos.y, altura, largura, RED);
}

void desenhar_inimigos(Inimigo inimigos[MAX_INIMIGOS], int n_inimigos) {
    for (int i = 0; i < n_inimigos; i++) {
        if (inimigos[i].vivo == 1)
            DrawRectangle(inimigos[i].pos.x, inimigos[i].pos.y, TAMANHO_INIMIGO, TAMANHO_INIMIGO, YELLOW);
    }
}

void desenhar_hud(int fase_num, float tempo) {
    char str_fase[100], str_tempo[100];

    sprintf(str_fase, "%d", fase_num);
    sprintf(str_tempo, "%.1f", tempo);

    DrawText(str_fase, TAM_FONTE, 10, TAM_FONTE, WHITE);       // Draw text (using default font)
    DrawText(str_tempo, LARGURA_JANELA - (TAM_FONTE * 3), 10, TAM_FONTE, WHITE); 
}

void desenhar_jogo(Jogo jogo) {
    ClearBackground(DARKGREEN);
    desenhar_mapa(jogo.mapa);
    desenhar_inimigos(jogo.inimigos, jogo.n_inimigos);
    desenhar_jogador(jogo.jogador.pos, TAMANHO_PERSONAGEM, TAMANHO_PERSONAGEM);
    desenhar_hud(jogo.fase_num, jogo.tempo);
}

void desenhar_menu() {
    ClearBackground(ORANGE);
    DrawText("MENU", GetScreenWidth()/3, GetScreenHeight()/2, 60, WHITE); 
    DrawText("SPACE PARA COMECAR", GetScreenWidth()/4, GetScreenHeight()/4 * 3, TAM_FONTE, WHITE); 
}

void desenhar_tela_perdeu(Ambiente * ambiente) {
    char texto[50] = {0};
    sprintf(texto, "Tempo de jogo: %.1f", ambiente->jogo.tempo);
    ClearBackground(RED);
    DrawText("VOCE PERDEU", GetScreenWidth()/4, GetScreenHeight()/2, 60, WHITE); 
    DrawText(texto, GetScreenWidth()/4, GetScreenHeight()/8, TAM_FONTE, WHITE); 
    DrawText("SPACE para voltar ao menu", GetScreenWidth()/4, GetScreenHeight()/4 * 3, TAM_FONTE, WHITE); 
    
}

void desenhar_tela_ganhou(Ambiente * ambiente) {
    char texto[50] = {0};
    sprintf(texto, "Tempo de jogo: %.1f", ambiente->jogo.tempo);
    ClearBackground(GREEN);
    DrawText("VOCE PERDEU", GetScreenWidth()/4, GetScreenHeight()/2, 60, WHITE); 
    DrawText(texto, GetScreenWidth()/4, GetScreenHeight()/8, TAM_FONTE, WHITE); 
    DrawText("SPACE para voltar ao menu", GetScreenWidth()/4, GetScreenHeight()/4 * 3, TAM_FONTE, WHITE); 
    
}

void desenhar_pausa (Ambiente *ambiente){
    //o jogo parado, como fundo
    desenhar_jogo(ambiente->jogo);

    //tamanho da caixa
    int largura_caixa = LARGURA_JANELA * 0.6;
    int altura_caixa  = ALTURA_JANELA * 0.4; 
    //caixa no centro:
    int x_caixa = (LARGURA_JANELA - largura_caixa) / 2;
    int y_caixa = (ALTURA_JANELA - altura_caixa) / 2;

    //fundo escuro na caixa
    DrawRectangle(x_caixa, y_caixa, largura_caixa, altura_caixa, Fade(PINK, 0.9f));

    char titulo[] = "PAUSADO";
    char dica[]   = "Aperte P para continuar";

    int x_titulo = x_caixa + (largura_caixa - MeasureText(titulo, TAM_FONTE*2)) / 2;
    int x_dica   = x_caixa + (largura_caixa - MeasureText(dica, TAM_FONTE)) / 2;


    DrawText(titulo, x_titulo, y_caixa + altura_caixa / 4,     TAM_FONTE*2, BLACK);
    DrawText(dica,   x_dica,   y_caixa + altura_caixa * 2 / 3, TAM_FONTE,   BLACK);

}