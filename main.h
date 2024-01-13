#define COMPUTADOR 0
#define JOGADOR 1
#define TAMANHO_MAPA 3

extern char mapa[TAMANHO_MAPA][TAMANHO_MAPA];

void abertura();
void iniciaMapa();
void imprimeMapa();
void vezJogador(char indicador);
void vezComputador(char indicador);
int verificaSeAcabou(char indicador, int contadorDeJogadas);
int posicaoVazia(int X, int Y, int vezDeQuem);