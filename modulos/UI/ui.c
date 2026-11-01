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
        printf("VOCE PERDEU\n");
    }

    if (IsKeyDown(KEY_SPACE)) {
        menu(ambiente);
    }
}

