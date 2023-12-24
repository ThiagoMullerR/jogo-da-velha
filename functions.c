#include <stdio.h>
#include "main.h"

void iniciaMapa(){
    for(int x = 0; x < TAMANHO_MAPA; x++){
        for(int y = 0; y < TAMANHO_MAPA; y++){
            mapa[x][y] = ' ';
        }
    }
}

void imprimeMapa(){
    printf("\n");
    for(int x = 0; x < TAMANHO_MAPA; x++){
        for(int y = 0; y < TAMANHO_MAPA; y++){
            printf("%c", mapa[x][y]);
            if(y < TAMANHO_MAPA - 1) printf("|");
        }
        if(x < TAMANHO_MAPA - 1){
            printf("\n");
            for(int i = 0; i < TAMANHO_MAPA; i++) printf("_ ");
            printf("\n");
        }
    }
    printf("\n\n");
}

int verificaSeGanhou(char indicador){

    int cDiagonalEsqDir = 0; int cDiagonalDirEsq = 0;
    for(int x = 0; x < TAMANHO_MAPA; x++){

        int cLinhas = 0; int cColunas = 0;
        for(int y = 0; y < TAMANHO_MAPA; y++){

            // Verifica Linhas e colunas
            if(mapa[x][y] == indicador) cLinhas++;
            if(mapa[y][x] == indicador) cColunas++;

            //Verifica diagonais
            if(x == y) if(mapa[x][y] == indicador) cDiagonalEsqDir++;
            if(y == TAMANHO_MAPA - x - 1) if(mapa[x][y] == indicador) cDiagonalDirEsq++;

            if(cLinhas == TAMANHO_MAPA || cColunas == TAMANHO_MAPA ||
             cDiagonalEsqDir == TAMANHO_MAPA || cDiagonalDirEsq == TAMANHO_MAPA){
                printf("%c é o vencedor!\n", indicador);
                return 1;
            }

        }
    }

    //Não houve combinação
    return 0;

}

int posicaoVazia(int X, int Y, int vezDeQuem){
    if(mapa[X][Y] != ' '){
        if (vezDeQuem == JOGADOR) printf("Posição em uso! Escolha outra posição.\n");
        return 0;
    } else return 1;
}