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
    //Condição 1
    // x|x|x
    // _ _ _
    //  | | 
    // _ _ _
    //  | | 
    if(mapa[0][0] == indicador && mapa[0][1] == indicador && mapa[0][2] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }
    
    //Condição 2
    //  | | 
    // _ _ _
    // x|x|x
    // _ _ _
    //  | | 
    if(mapa[1][0] == indicador && mapa[1][1] == indicador && mapa[1][2] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }

    //Condição 3
    //  | | 
    // _ _ _
    //  | | 
    // _ _ _
    // x|x|x
    if(mapa[2][0] == indicador && mapa[2][1] == indicador && mapa[2][2] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }

    //Condição 4
    // x| | 
    // _ _ _
    // x| | 
    // _ _ _
    // x| | 
    if(mapa[0][0] == indicador && mapa[1][0] == indicador && mapa[2][0] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }

    //Condição 5
    //  |x| 
    // _ _ _
    //  |x| 
    // _ _ _
    //  |x| 
    if(mapa[0][1] == indicador && mapa[1][1] == indicador && mapa[2][1] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }

    //Condição 6
    //  | |x
    // _ _ _
    //  | |x
    // _ _ _
    //  | |x
    if(mapa[0][2] == indicador && mapa[1][2] == indicador && mapa[2][2] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }

    //Condição 7
    // x| | 
    // _ _ _
    //  |x| 
    // _ _ _
    //  | |x
   if(mapa[0][0] == indicador && mapa[1][1] == indicador && mapa[2][2] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }

    //Condição 8
    //  | |x
    // _ _ _
    //  |x| 
    // _ _ _
    // x| | 
    if(mapa[0][2] == indicador && mapa[1][1] == indicador && mapa[2][0] == indicador){
        printf("%c é o vencedor!\n", indicador);
        return 1;
    }

    //Não houve combinação
    else return 0;
}

int posicaoVazia(int X, int Y, int vezDeQuem){
    if(mapa[X][Y] != ' '){
        if (vezDeQuem == JOGADOR) printf("Posição em uso! Escolha outra posição.\n");
        return 0;
    } else return 1;
}