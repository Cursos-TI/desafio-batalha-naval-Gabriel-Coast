#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3
#define AGUA 0

int main() {
    // Declaração do tabuleiro e inicialização com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Vetor representando um navio de tamanho 3
    int navio[TAMANHO_NAVIO] = {OCUPADO, OCUPADO, OCUPADO};

    // Coordenadas iniciais dos 4 navios
    int linha_h1 = 1, coluna_h1 = 2;   // Navio horizontal
    int linha_v1 = 4, coluna_v1 = 7;   // Navio vertical
    int linha_d1 = 0, coluna_d1 = 0;   // Navio diagonal principal (↘)
    int linha_d2 = 0, coluna_d2 = 9;   // Navio diagonal secundária (↙)

    int i, sobreposicao = 0;

    // --- Validação de Limites para os Navios ---

    // Navio Horizontal
    if (coluna_h1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal 1 fora dos limites!\n");
        return 1;
    }

    // Navio Vertical
    if (linha_v1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical 1 fora dos limites!\n");
        return 1;
    }

    // Navio Diagonal Principal (↘)
    if (linha_d1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_d1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio diagonal 1 fora dos limites!\n");
        return 1;
    }

    // Navio Diagonal Secundária (↙)
    if (linha_d2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna_d2 - (TAMANHO_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal 2 fora dos limites!\n");
        return 1;
    }

    // --- Verificação de Sobreposição dos Navios ---

    // Horizontal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_h1][coluna_h1 + i] != AGUA) {
            sobreposicao = 1;
            break;
        }
    }

    // Vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_v1 + i][coluna_v1] != AGUA) {
            sobreposicao = 1;
            break;
        }
    }

    // Diagonal Principal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_d1 + i][coluna_d1 + i] != AGUA) {
            sobreposicao = 1;
            break;
        }
    }

    // Diagonal Secundária
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_d2 + i][coluna_d2 - i] != AGUA) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: Sobreposição de navios detectada!\n");
        return 1;
    }

    // --- Posicionamento dos Navios ---

    // Horizontal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h1][coluna_h1 + i] = navio[i];
    }

    // Vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v1 + i][coluna_v1] = navio[i];
    }

    // Diagonal Principal (↘)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = navio[i];
    }

    // Diagonal Secundária (↙)
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = navio[i];
    }

    // --- Exibição do Tabuleiro ---
    printf("\nTabuleiro de Batalha Naval:\n\n");

    // Cabeçalho das colunas
    printf("   ");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha); // Número da linha
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%2d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
