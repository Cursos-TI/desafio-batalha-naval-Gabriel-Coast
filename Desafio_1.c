#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro 10x10 e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Vetores representando os navios (não é obrigatório, mas vamos usar para seguir o enunciado)
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais para os navios
    int linha_horizontal = 2; // Linha inicial do navio horizontal
    int coluna_horizontal = 4; // Coluna inicial do navio horizontal

    int linha_vertical = 5; // Linha inicial do navio vertical
    int coluna_vertical = 7; // Coluna inicial do navio vertical

    int i, sobreposicao = 0;

    // Validação: Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1; // Encerra o programa com erro
    }

    // Validação: Verifica se o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Verificação de sobreposição para o navio horizontal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
            sobreposicao = 1;
            break;
        }
    }

    // Verificação de sobreposição para o navio vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: Sobreposição de navios detectada!\n");
        return 1;
    }

    // Posicionamento do navio horizontal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posicionamento do navio vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    
    return 0;
}
