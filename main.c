#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "main.h"


char mapa[TAMANHO_MAPA][TAMANHO_MAPA];

int main(int argc, char const *argv[]){

    char indicador, indicadorInimigo;
    int contadorDeJogadas = 0; // Max 9.
    srand(time(NULL));

    printf("Bem-vindo(a) ao jogo da velha!\n\n");

    //Escolha X ou O
    int indicadorValido = 0;
    while (indicadorValido != 1){
        printf("Você deseja jogar com X ou O? ");
        scanf(" %c", &indicador);
        indicador = toupper(indicador);

        if(indicador != 'X' && indicador != 'O'){
            printf("Valor incorreto!\n");
        }else if (indicador == 'X'){
            indicadorInimigo = 'O';
            indicadorValido = 1;
        }else if (indicador == 'O'){
            indicadorInimigo = 'X';
            indicadorValido = 1;
        }
    }
    
    printf("O oponente será %c!\n", indicadorInimigo);

    iniciaMapa();
    
    //Vez do jogador
    int acabou = 0;
    while (acabou == 0){
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
                                
            } else printf("Valor inválido!\nEscolha um valor de 1 a 3.\n");
        }
        mapa[X][Y] = indicador;
        contadorDeJogadas++;
        
        if(verificaSeGanhou(indicador)){
            acabou = 1;
            imprimeMapa();

        } else{

            //Vez do computador
            imprimeMapa();
    
            contadorDeJogadas++;

            if(contadorDeJogadas > TAMANHO_MAPA * TAMANHO_MAPA){
                printf("Deu velha! O jogo empatou!\n");
                acabou = 1;
            } else{
                    int jogadaValidaPC = 0;
                    while(jogadaValidaPC != 1){
                        X = rand() % TAMANHO_MAPA;
                        Y = rand() % TAMANHO_MAPA;

                        if(posicaoVazia(X, Y, COMPUTADOR)){
                            mapa[X][Y] = indicadorInimigo;
                            jogadaValidaPC++;
                            printf("O oponente %c jogou linha %d e coluna %d.\n", indicadorInimigo, X + 1, Y + 1);
                            
                        }
                    }

                    if(verificaSeGanhou(indicadorInimigo)){
                        acabou = 1;
                        imprimeMapa();
                    }
                }
        }

    }
    
    printf("Fim de jogo!\n");
    EXIT_SUCCESS;
}