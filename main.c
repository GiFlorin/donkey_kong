#include <raylib.h>
#include <stdio.h>

// modulos locais
#include "mapa/mapa.h"
#include "constantes/constantes.h"
#include "render/render.h"
#include "tipos/tipos.h"
#include "jogo/jogo.h"
#include "ui/ui.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    // DECLARACAO VARIAVEIS DO JOGO
    Ambiente ambiente = {0};
    ambiente.estado_tela = TELA_MENU;
    strcpy(ambiente.jogo.caminho_fase, "mapas/mapa1.txt");
    
    // inicializar tela
    InitWindow(ALTURA_JANELA, LARGURA_JANELA, "Donkey Kong");
    SetTargetFPS(FPS_ALVO);

    while (!WindowShouldClose())
    {
        switch (ambiente.estado_tela) {
            case TELA_MENU: menu(&ambiente); break;

            case TELA_NIVEIS: printf("TELA LISTA DE NIVEIS\n"); break;
            
            case TELA_JOGANDO: atualizar_jogo(&ambiente); break;

            case TELA_PAUSA: printf("TELA PAUSE\n"); break;

            case TELA_PERDEU: tela_perdeu(&ambiente); break;
            
            case TELA_GANHOU: printf("TELA FIM-> GANHOU\n"); break;

            case TELA_NOME: printf("TELA ESCREVA O SEU NOME\n"); break;

            case TELA_SAIR: printf("TELA SAINDO...\n"); break;

            default: printf("ERRO: Estado de tela inválido\n"); break;
        }
        // DESENHAR
        BeginDrawing();
        switch (ambiente.estado_tela) {
            case TELA_MENU: desenhar_menu(); break;

            case TELA_NIVEIS: printf("TELA LISTA DE NIVEIS\n"); break;
            
            case TELA_JOGANDO: desenhar_jogo(ambiente.jogo); break;

            case TELA_PAUSA: printf("TELA PAUSE\n"); break;

            case TELA_PERDEU: desenhar_tela_perdeu(); break;
            
            case TELA_GANHOU: printf("TELA FIM-> GANHOU\n"); break;

            case TELA_NOME: printf("TELA ESCREVA O SEU NOME\n"); break;

            case TELA_SAIR: printf("TELA SAINDO...\n"); break;

            default: printf("ERRO: Estado de tela inválido\n"); break;
        
        }
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
