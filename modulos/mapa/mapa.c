/*lida com o arquivo do mapa, carrega o mapa*/

#include "mapa.h"
#include <stdio.h>
#include <string.h>
#include <raylib.h>
#include "constantes/constantes.h"
#include "tipos/tipos.h"

void carregar_nivel(Jogo * jogo) {
    ler_arquivo(MAPA_LINHAS, MAPA_COLUNAS, jogo->caminho_fase, jogo->mapa); // carrega o mapa do arquivo de texto
    
    jogo->jogador.pos = player_spawn_pos(MAPA_LINHAS, MAPA_COLUNAS, jogo->mapa); // posicao inicial do jogador

    // carregar inimigos
    jogo->n_inimigos = carregar_inimigos(jogo->mapa, jogo->inimigos);

}

int ler_arquivo(int lin, int col, char caminho[MAX_CAMINHO], char destino[lin][col]) {  // retorna 1 com sucesso e 0 com erro
    /*fopen → confere se dá para abrir
      → para cada linha:
            fgets → tira \n → confere tamanho → strcpy
      → fclose
    */

    // ponteiro para o arquivo do mapa
    FILE *pArq = fopen(caminho, "r"); // modo r de 'read'
    char linha[128] = {0}; // tamanho do mapa = 30 x 30

    if (pArq == NULL) { // se não conseguir abrir o arquivo a variavel fica com o valor NULL
        printf("ERRO: Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    // LENDO O ARQUIVO
    for (int l = 0; l < lin; l++) { // percorre as linhas do arquivo até lin - 1

        if (!fgets(linha, sizeof(linha), pArq)) { // ERRO: (fgets le a linha do arquivo), se o arquivo acabar antes do esperado
            printf("ERRO: arquivo menor do que o esperado\n");
            fclose(pArq); // fechar o arquivo
            return 0;
        }

        linha[strcspn(linha, "\r\n")] = '\0'; // remove o \n da string

        if (strlen(linha) != (size_t)lin) { // ERRO: se a linha tiver o tamanho errado
            printf("ERRO: linha com o tamanho errado\n");
            fclose(pArq); // fechar o arquivo
            return 0;
        }
        
        // copia a linha para a matriz de destino
        memset(destino[l], ' ', col); // limpa a memoria
        memcpy(destino[l], linha, col); // copia para a matriz(sem o \0)
    }

    fclose(pArq); // fechar o arquivo
    return 1;
}

Vector2 player_spawn_pos(int lin, int col, char map[lin][col]) { // encontrar a posicao inicial do personagem
    Vector2 pos = {0, 0};
    for(int l = 0; l < lin; l++) {

        for(int c = 0; c < col; c++) {
            if (map[l][c] == POS_INI_JOGADOR) {
                pos.x = (GetScreenWidth()/col) * c;
                pos.y = (GetScreenHeight()/lin) * l;
            }
        }
    }
    return pos;
}

int carregar_inimigos(char mapa[MAPA_LINHAS][MAPA_COLUNAS], Inimigo inimigos[MAX_INIMIGOS]) { // retorna o n de inimigos
    int cont = 0;

    for(int l = 0; l < MAPA_LINHAS; l++) {
        for(int c = 0; c < MAPA_COLUNAS; c++) {
            if (mapa[l][c] == INIMIGOS) {
                inimigos[cont].pos.x = (GetScreenWidth()/MAPA_COLUNAS) * c;
                inimigos[cont].pos.y = (GetScreenHeight()/MAPA_LINHAS) * l;
                inimigos[cont].vivo = 1;
                inimigos[cont].dir = 1;
                cont++;
            }
        }
    }
    return cont;
}
