#include "ui.h"
#include <raylib.h>
#include "tipos/tipos.h"
#include "constantes/constantes.h"
#include "render/render.h"
#include "jogo/jogo.h"
#include <stdio.h>

void menu(Ambiente * ambiente) {
    if (ambiente->estado_tela != TELA_MENU) {
        ambiente->estado_tela = TELA_MENU;
        printf("Entrando no menu\n");
    }

    if (IsKeyDown(KEY_SPACE)) {
        inicializar_jogo(ambiente);
    }
}

void tela_perdeu(Ambiente * ambiente) {
    if (ambiente->estado_tela != TELA_PERDEU) {
        ambiente->estado_tela = TELA_PERDEU;
    }

    if (IsKeyDown(KEY_SPACE)) { // vai para o menu ao apertar espaço
        menu(ambiente);
    }
}

void tela_ganhou(Ambiente * ambiente) {
    if (ambiente->estado_tela != TELA_GANHOU) { // muda o estado da tela quando entra na funcao
        ambiente->estado_tela = TELA_GANHOU;
        printf("VOCE GANHOU\n");
    }

    if (IsKeyDown(KEY_SPACE)) { // vai para o menu ao apertar espaço
        menu(ambiente);
    }
}

void pausa(Ambiente *ambiente) {
    if (IsKeyPressed(KEY_P)) {
        ambiente->estado_tela = TELA_JOGANDO;
    }
}

