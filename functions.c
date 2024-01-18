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
    printf("  Criado por ThiagoMullerR - github.com/ThiagoMullerR   \n\n");
}

void carregaMapa(MAPA* mapa){
    int tamanhoMapa = 3;
    FILE *arquivo;

    arquivo = fopen("mapa.txt", "r");

    if(arquivo == NULL){
        tamanhoMapa = 3;
        //printf("Arquivo nulo!\n");
    } else {
        fscanf(arquivo, "%d", &tamanhoMapa);
        fclose(arquivo);

        if (tamanhoMapa < 2 || tamanhoMapa > 50) tamanhoMapa = 3;
        printf("\nMapa %dx%d carregado!\n", tamanhoMapa, tamanhoMapa);
    }
    mapa->linhas = tamanhoMapa; mapa->colunas = tamanhoMapa;

    alocaMapa(mapa);
    iniciaMapa(mapa);
}

void alocaMapa(MAPA* mapa){
    mapa->matriz = malloc(sizeof(char*) * mapa->linhas);
    for (int i = 0; i < mapa->linhas; i++){
        mapa->matriz[i] = malloc(sizeof(char) * (mapa->colunas + 1));
    }
}

void iniciaMapa(MAPA* mapa){
    for(int x = 0; x < mapa->linhas; x++){
        for(int y = 0; y < mapa->colunas; y++){
            mapa->matriz[x][y] = ' ';
        }
    }
}

void finalizaMapa(MAPA* mapa){
    for (int i = 0; i < mapa->linhas; i++){
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
}

void imprimeMapa(MAPA* mapa){
    printf("\n");

    // Imprime a numeração das colunas
    printf("   ");
    for (int coluna = 1; coluna <= mapa->colunas; coluna++) printf("%-5d ", coluna);
    printf("\n");

    for (int x = 0; x < mapa->linhas; x++) {
        for (int i = 1; i < 3; i++) {
            // Imprime o número da linha
            if (i == 2) printf("%-1d", x + 1);
            for (int y = 0; y < mapa->colunas; y++) {
                if (y > 0) printf("|");
                if (i == 1 && y == 0) printf(" ");
                if (i == 2) printf("  %c  ", mapa->matriz[x][y]);
                else printf("     ");
            }
            printf("\n");
        }

        if (x < mapa->linhas - 1) {
            for (int i = 0; i < mapa->colunas; i++) {
                if (i > 0) printf("|");
                if (i == 0) printf(" ");
                printf("_____");
            }
            printf("\n");

        } else {
            for (int i = 0; i < mapa->colunas; i++) {
                if (i > 0) printf("|");
                if (i == 0) printf(" ");
                printf("     ");
            }
            printf("\n");

        }
    }
    printf("\n");
}

void vezJogador(MAPA* mapa, char indicador){
    printf("Vez do jogador %c!\n", indicador);

    imprimeMapa(mapa);
    
    int X, Y = 0;
    int validaInput = 0;
    while(validaInput != 1){
        printf("Indique a linha e a coluna com um espaço entre os números: ");
        scanf("%d %d", &X, &Y);

        if(X <= mapa->linhas && X >= 1 && Y <= mapa->colunas && Y >= 1){
            X--; Y--;
            //Verifica
            validaInput = posicaoVazia(mapa, X, Y, JOGADOR);
                            
        } else printf("Valor inválido!\nEscolha um valor de 1 a %d.\n", mapa->linhas);
    }
    mapa->matriz[X][Y] = indicador;
}

void vezComputador(MAPA * mapa, char indicador){
    printf("Vez do jogador %c!\n", indicador);

    imprimeMapa(mapa);
    
    sleep(1);

    int X, Y = 0;
    int jogadaValidaPC = 0;
    while(jogadaValidaPC != 1){
        X = rand() % mapa->linhas;
        Y = rand() % mapa->colunas;

        if(posicaoVazia(mapa, X, Y, COMPUTADOR)){
            mapa-> matriz[X][Y] = indicador;
            jogadaValidaPC++;
            printf("O oponente %c jogou linha %d e coluna %d.\n", indicador, X + 1, Y + 1);
            
        }
    }
}

int verificaSeAcabou(MAPA* mapa, char indicador, int contadorDeJogadas){

    // Verifica se alguém ganhou
    int cDiagonalEsqDir = 0; int cDiagonalDirEsq = 0;
    for(int x = 0; x < mapa->linhas; x++){

        int cLinhas = 0; int cColunas = 0;
        for(int y = 0; y < mapa->colunas; y++){

            // Verifica Linhas e colunas
            if(mapa->matriz[x][y] == indicador) cLinhas++;
            if(mapa->matriz[y][x] == indicador) cColunas++;

            //Verifica diagonais
            if(x == y) if(mapa->matriz[x][y] == indicador) cDiagonalEsqDir++;
            if(y == mapa->colunas - x - 1) if(mapa->matriz[x][y] == indicador) cDiagonalDirEsq++;

            if(cLinhas == mapa->linhas || cColunas == mapa->colunas ||
             cDiagonalEsqDir == mapa->linhas || cDiagonalDirEsq == mapa->colunas){
                printf("%c é o vencedor!\n", indicador);
                return 1;
            }

        }
    }

    // Verifica se deu velha
    if(contadorDeJogadas + 1 > mapa->linhas * mapa->colunas){
        printf("Deu velha! O jogo empatou!\n");
        return 1;
    }

    // Não houve combinação
    return 0;

}

int posicaoVazia(MAPA* mapa, int X, int Y, int vezDeQuem){
    if(mapa->matriz[X][Y] != ' '){
        if (vezDeQuem == JOGADOR) printf("Posição em uso! Escolha outra posição.\n");
        return 0;
    } else return 1;
}
