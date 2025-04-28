#include <stdio.h>
#include <stdlib.h> // Para a função abs()

#define Linha 7
#define Coluna 7 // Tamanho fixo das matrizes de habilidades

// Função para criar matriz em forma de Cone
void criarCone(int cone[Linha][Coluna]) {
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            if (j >= (Linha / 2) - i && j <= (Coluna / 2) + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz em forma de Cruz
void criarCruz(int cruz[Linha][Coluna]) {
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            if (i == Linha / 2 || j == Coluna / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz em forma de Octaedro (losango)
void criarOctaedro(int octaedro[Linha][Coluna]) {
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            if (abs(i - Linha / 2) + abs(j - Coluna / 2) <= Linha / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Função para exibir qualquer matriz de habilidade
void exibirMatriz(int matriz[Linha][Coluna]) {
    for (int i = 0; i < Linha; i++) {
        for (int j = 0; j < Coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int cone[Linha][Coluna];
    int cruz[Linha][Coluna];
    int octaedro[Linha][Coluna];

    // Criando as habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Exibindo as habilidades
    printf("Matriz Cone:\n");
    exibirMatriz(cone);

    printf("Matriz Cruz:\n");
    exibirMatriz(cruz);

    printf("Matriz Octaedro:\n");
    exibirMatriz(octaedro);

    return 0;
}
