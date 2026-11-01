#ifndef JOGO_H
#define JOGO_H
#include <stdio.h>
#include "tipos/tipos.h"
#include "jogador/jogador.h"
#include <raylib.h>

void inicializar_jogo(Ambiente * ambiente);

void atualizar_jogo(Ambiente * ambiente);

#endif
