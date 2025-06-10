#include <stdio.h>

#define N 10          // Tamanho do tabuleiro
#define TAM_NAVIO 3   // Tamanho fixo dos navios
#define MAR 0         // Representa água
#define NAVIO 3       // Representa parte do navio

int main() {
    int tab[N][N];
    int i, j;

    // Inicializa o tabuleiro com água
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            tab[i][j] = MAR;

    int erro = 0;


    // 1. Navio horizontal: começa em (1,2)
    int linhaH = 1, colH = 2;
    if (colH + TAM_NAVIO <= N) {
        for (i = 0; i < TAM_NAVIO; i++)
            if (tab[linhaH][colH + i] != MAR)
                erro = 1;

        if (!erro)
            for (i = 0; i < TAM_NAVIO; i++)
                tab[linhaH][colH + i] = NAVIO;
    } else {
        erro = 1;
    }

    // 2. Navio vertical: começa em (4,7)
    int linhaV = 4, colV = 7;
    if (linhaV + TAM_NAVIO <= N) {
        for (i = 0; i < TAM_NAVIO; i++)
            if (tab[linhaV + i][colV] != MAR)
                erro = 1;

        if (!erro)
            for (i = 0; i < TAM_NAVIO; i++)
                tab[linhaV + i][colV] = NAVIO;
    } else {
        erro = 1;
    }

    // 3. Navio diagonal principal ↘: começa em (0,0)
    int linD1 = 0, colD1 = 0;
    if (linD1 + TAM_NAVIO <= N && colD1 + TAM_NAVIO <= N) {
        for (i = 0; i < TAM_NAVIO; i++)
            if (tab[linD1 + i][colD1 + i] != MAR)
                erro = 1;

        if (!erro)
            for (i = 0; i < TAM_NAVIO; i++)
                tab[linD1 + i][colD1 + i] = NAVIO;
    } else {
        erro = 1;
    }

    // 4. Navio diagonal secundária ↙: começa em (2,7)
    int linD2 = 2, colD2 = 7;
    if (linD2 + TAM_NAVIO <= N && colD2 - TAM_NAVIO + 1 >= 0) {
        for (i = 0; i < TAM_NAVIO; i++)
            if (tab[linD2 + i][colD2 - i] != MAR)
                erro = 1;

        if (!erro)
            for (i = 0; i < TAM_NAVIO; i++)
                tab[linD2 + i][colD2 - i] = NAVIO;
    } else {
        erro = 1;
    }

    // Cabeçalho com letras
    printf("    ");
    for (j = 0; j < N; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Imprime cada linha com número à esquerda
    for (i = 0; i < N; i++) {
        printf("%2d: ", i + 1);  // Números de 1 a 10
        for (j = 0; j < N; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}