#include "mapa.h"
#include <stdio.h>
#include <string.h>
#include <raylib.h>

int ler_arquivo(int lin, int col, char destino[lin][col]) {  // retorna 1 com sucesso e 0 com erro
    /*fopen → confere se dá para abrir
      → para cada linha:
            fgets → tira \n → confere tamanho → strcpy
      → fclose
    */

    // ponteiro para o arquivo do mapa
    FILE *pArq = fopen("maps/mapa1.txt", "r"); // modo r de 'read'
    char linha[128] = {0}; // tamanho do mapa = 30 x 30

    if (pArq == NULL) { // se não conseguir abrir o arquivo a variavel fica com o valor NULL
        printf("ERRO: Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    // LENDO O ARQUIVO
    for (int l = 0; l < lin; l++) { // percorre as linhas do arquivo até lin - 1

        if (!fgets(linha, sizeof(linha), pArq)) { // (fgets le a linha do arquivo), se o arquivo acabar antes do esperado, retorna e dá um erro
            printf("ERRO: arquivo menor do que o esperado\n");
            return 0;
        }

        linha[strcspn(linha, "\r\n")] = '\0'; // remove o \n da string

        if (strlen(linha) != (size_t)lin) { // se a linha tiver o tamanho errado
            printf("ERRO: linha com o tamanho errado\n");
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
            if (map[l][c] == 'P') {
                pos.x = (GetScreenWidth()/col) * c;
                pos.y = (GetScreenHeight()/lin) * l;
            }
        }
    }
    return pos;
}
