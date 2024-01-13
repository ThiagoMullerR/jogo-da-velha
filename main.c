#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "main.h"


char mapa[TAMANHO_MAPA][TAMANHO_MAPA];

int main(int argc, char const *argv[]){

    char indicador;
    char indicadorInimigo;
    int X, Y = 0;
    int contadorDeJogadas = 0;
    int jogadores = 0; // 1 (jogador x Computador) - 2 (Jogador x Jogador)

    srand(time(NULL));
    
    abertura();

    int indicadorValido = 0;
    while (indicadorValido != 1){
        printf("Você deseja jogar com X ou O? ");
        scanf(" %c", &indicador);
        indicador = toupper(indicador);

        if(indicador != 'X' && indicador != 'O'){
            printf("Valor incorreto! Escolha X ou O.\n");
        }else if (indicador == 'X'){
            indicadorInimigo = 'O';
            indicadorValido = 1;
        }else if (indicador == 'O'){
            indicadorInimigo = 'X';
            indicadorValido = 1;
        }
    }
    
    printf("O oponente será %c!\n", indicadorInimigo);


    printf("Você vai jogar contra o computador ou contra outro jogador?\n(1) Computador\n(2) Jogador\n");
    int jogadorValido = 0;
    while(jogadorValido != 1){
        scanf("%d", &jogadores);
        if(jogadores != 1 && jogadores != 2){
            printf("Valor incorreto. Escolha 1 Para Computador ou 2 para Jogador.\n");
        } else {
            jogadorValido = 1;
        }
    }

    iniciaMapa();
    
    int acabou = 0;
    while (acabou == 0){
        vezJogador(indicador);
        contadorDeJogadas++;
        acabou = verificaSeAcabou(indicador, contadorDeJogadas);
        imprimeMapa();
        if(acabou) break;


        if(jogadores == 1){
            vezComputador(indicadorInimigo);
            contadorDeJogadas++;
            acabou = verificaSeAcabou(indicadorInimigo, contadorDeJogadas);
            imprimeMapa();

        } else if (jogadores == 2) {
            vezJogador(indicadorInimigo);
            contadorDeJogadas++;
            acabou = verificaSeAcabou(indicadorInimigo, contadorDeJogadas);
            imprimeMapa();
        }
    }

    printf("Fim de jogo!\n");
    EXIT_SUCCESS;
}