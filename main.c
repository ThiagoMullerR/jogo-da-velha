#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include "main.h"


char mapa[TAMANHO_MAPA][TAMANHO_MAPA];

int main(int argc, char const *argv[]){

    char indicador;
    char indicadorInimigo;
    int contadorDeJogadas = 0; // Max 9.
    int jogadores = 0; // 1 (jogador x Computador) - 2 (Jogador x Jogador)
    srand(time(NULL));

    printf("Bem-vindo(a) ao jogo da velha!\n\n");

    //Escolha X ou O
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
        printf("Vez do jogador %c!\n", indicador);

        //Vez do jogador
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
        contadorDeJogadas++;
        
        if(verificaSeGanhou(indicador)){
            acabou = 1;
            imprimeMapa();

        } else{

            if(jogadores == 1){
                printf("Vez do jogador %c!\n", indicadorInimigo);

                //Vez do computador
                imprimeMapa();
                
                sleep(1);
        
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

                // Fim da vez do computador
            } else if (jogadores == 2) {
                printf("Vez do jogador %c!\n", indicadorInimigo);

                imprimeMapa();
                
                int X2, Y2 = 0;
                int validaInput2 = 0;
                while(validaInput2 != 1){
                    printf("Indique a linha e a coluna com um espaço entre os números: ");
                    scanf("%d %d", &X2, &Y2);

                    if(X2 <= TAMANHO_MAPA && X2 >= 1 && Y2 <= TAMANHO_MAPA && Y2 >= 1){
                        X2--;
                        Y2--;
                        //Verifica
                        validaInput2 = posicaoVazia(X2, Y2, JOGADOR);
                                        
                    } else printf("Valor inválido!\nEscolha um valor de 1 a %d.\n", TAMANHO_MAPA);
                }
                mapa[X2][Y2] = indicadorInimigo;
                contadorDeJogadas++;
                
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