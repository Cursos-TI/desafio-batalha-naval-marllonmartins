#include <stdio.h>

#define N 10
#define TAM_NAVIO 3


int  main(){
    int tab[N][N];
    int i, j;

    // Inicializa o tabuleiro como água (0)
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tab[i][j] = 0;
            


    // Tamanho fixo dos navios
    int navio[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais no código
    int linhaH = 1, colH = 2;  // navio horizontal começa em (1,2)
    int linV = 4, colV = 7;    // navio vertical começa em (4,7)

    int erro = 0;

    // Posicionar navio horizontal
    if (colH + TAM_NAVIO <= N) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tab[linhaH][colH + i] != 0) {
                erro = 1;
                printf("Erro: sobreposição no navio horizontal.\n");
            }
        }
        if (!erro) {
            for (i = 0; i < TAM_NAVIO; i++)
                tab[linhaH][colH + i] = navio[i];
        }
    } else {
        erro = 1;
        printf("Erro: navio horizontal fora do tabuleiro.\n");
    }

    // Posicionar navio vertical
    if (linV + TAM_NAVIO <= N) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tab[linV + i][colV] != 0) {
                erro = 1;
                printf("Erro: sobreposição no navio vertical.\n");
            }
        }
        if (!erro) {
            for (i = 0; i < TAM_NAVIO; i++)
                tab[linV + i][colV] = navio[i];
        }
    } else {
        erro = 1;
        printf("Erro: navio vertical fora do tabuleiro.\n");
    }


// Cabeçalho das colunas com letras
printf("    ");
for (j = 0; j < N; j++) {
    printf("%c ", 'A' + j);  // Letras de A até J
}
printf("\n");

// Impressão do tabuleiro com numeração das linhas
for (i = 0; i < N; i++) {
    printf("%2d: ", i + 1);  // Mostra número da linha de 1 a 10
    for (j = 0; j < N; j++) {
        printf("%d ", tab[i][j]);
    }
    printf("\n");
}



    return 0;















}