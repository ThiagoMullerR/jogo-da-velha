#ifndef _MAIN_H_
#define _MAIN_H_

#define COMPUTADOR 0
#define JOGADOR 1


struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

void abertura();
void carregaMapa(MAPA* mapa);
void alocaMapa(MAPA* mapa);
void iniciaMapa(MAPA* mapa);
void finalizaMapa(MAPA* mapa);
void imprimeMapa(MAPA* mapa);
void vezJogador(MAPA* mapa, char indicador);
void vezComputador(MAPA * mapa, char indicador);
int verificaSeAcabou(MAPA* mapa, char indicador, int contadorDeJogadas);
int posicaoVazia(MAPA* mapa, int X, int Y, int vezDeQuem);

#endif