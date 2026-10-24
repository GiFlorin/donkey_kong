#include "mapa.h"
#include <stdio.h>
#include <string.h>

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
        strcpy(destino[l], linha); // copia a linha para a matriz de destino
    }

    fclose(pArq); // fechar o arquivo
    return 1;
}