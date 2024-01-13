#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

void abertura(){
    printf("                                                        \n");
    printf("      ██  ██████   ██████   ██████      ██████   █████  \n");
    printf("      ██ ██    ██ ██       ██    ██     ██   ██ ██   ██ \n");
    printf("      ██ ██    ██ ██   ███ ██    ██     ██   ██ ███████ \n");
    printf(" ██   ██ ██    ██ ██    ██ ██    ██     ██   ██ ██   ██ \n");
    printf("  █████   ██████   ██████   ██████      ██████  ██   ██ \n");
    printf("                                                        \n");
    printf("                                                        \n");
    printf("         ██    ██ ███████ ██      ██   ██  █████        \n");
    printf("         ██    ██ ██      ██      ██   ██ ██   ██       \n");
    printf("         ██    ██ █████   ██      ███████ ███████       \n");
    printf("          ██  ██  ██      ██      ██   ██ ██   ██       \n");
    printf("           ████   ███████ ███████ ██   ██ ██   ██       \n");
    printf("                                                        \n");
    printf(" Criado por ThiagoMullerR - github.com/ThiagoMullerR    \n");
}

void iniciaMapa(){
    for(int x = 0; x < TAMANHO_MAPA; x++){
        for(int y = 0; y < TAMANHO_MAPA; y++){
            mapa[x][y] = ' ';
        }
    }
}

void imprimeMapa() {
    printf("\n");

    // Imprime a numeração das colunas
    printf("   ");
    for (int coluna = 1; coluna <= TAMANHO_MAPA; coluna++) printf("%-5d ", coluna);
    printf("\n");

    for (int x = 0; x < TAMANHO_MAPA; x++) {
        for (int i = 1; i < 3; i++) {
            // Imprime o número da linha na mesma linha que mapa[x][y]
            if (i == 2) printf("%-1d", x + 1);
            for (int y = 0; y < TAMANHO_MAPA; y++) {
                if (y > 0) printf("|");

                // Adiciona um espaço extra na primeira linha de cada bloco
                if (i == 1 && y == 0) printf(" ");
                if (i == 2) printf("  %c  ", mapa[x][y]);
                else printf("     ");
            }
            printf("\n");
        }

        if (x < TAMANHO_MAPA - 1) {
            for (int i = 0; i < TAMANHO_MAPA; i++) {
                if (i > 0) printf("|");
                
                // Adiciona um espaço antes dos tracejados apenas na primeira coluna
                if (i == 0) printf(" ");
                printf("_____");
            }
            printf("\n");

        } else {
            for (int i = 0; i < TAMANHO_MAPA; i++) {
                if (i > 0) printf("|");
                
                // Adiciona um espaço antes dos tracejados apenas na primeira coluna
                if (i == 0) printf(" ");
                printf("     ");
            }
            printf("\n");

        }
    }
    printf("\n");
}

void vezJogador(char indicador){
    printf("Vez do jogador %c!\n", indicador);

    imprimeMapa();
    
    int X, Y = 0;
    int validaInput = 0;
    while(validaInput != 1){
        printf("Indique a linha e a coluna com um espaço entre os números: ");
        scanf("%d %d", &X, &Y);

        if(X <= TAMANHO_MAPA && X >= 1 && Y <= TAMANHO_MAPA && Y >= 1){
            X--;
            Y--;
            //Verifica
            validaInput = posicaoVazia(X, Y, JOGADOR);
                            
        } else printf("Valor inválido!\nEscolha um valor de 1 a %d.\n", TAMANHO_MAPA);
    }
    mapa[X][Y] = indicador;
}

void vezComputador(char indicador){
    printf("Vez do jogador %c!\n", indicador);

    imprimeMapa();
    
    sleep(1);

    int X, Y = 0;
    int jogadaValidaPC = 0;
    while(jogadaValidaPC != 1){
        X = rand() % TAMANHO_MAPA;
        Y = rand() % TAMANHO_MAPA;

        if(posicaoVazia(X, Y, COMPUTADOR)){
            mapa[X][Y] = indicador;
            jogadaValidaPC++;
            printf("O oponente %c jogou linha %d e coluna %d.\n", indicador, X + 1, Y + 1);
            
        }
    }
}

int verificaSeAcabou(char indicador, int contadorDeJogadas){

    // Verifica se alguém ganhou
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

    // Verifica se deu velha
    if(contadorDeJogadas + 1 > TAMANHO_MAPA * TAMANHO_MAPA){
        printf("Deu velha! O jogo empatou!\n");
        return 1;
    }

    // Não houve combinação
    return 0;

}

int posicaoVazia(int X, int Y, int vezDeQuem){
    if(mapa[X][Y] != ' '){
        if (vezDeQuem == JOGADOR) printf("Posição em uso! Escolha outra posição.\n");
        return 0;
    } else return 1;
}
