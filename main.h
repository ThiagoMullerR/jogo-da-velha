#define COMPUTADOR 0
#define JOGADOR 1
#define TAMANHO_MAPA 3

extern char mapa[TAMANHO_MAPA][TAMANHO_MAPA];

void iniciaMapa();
void imprimeMapa();
int verificaSeGanhou(char indicador);
int posicaoVazia(int X, int Y, int vezDeQuem);