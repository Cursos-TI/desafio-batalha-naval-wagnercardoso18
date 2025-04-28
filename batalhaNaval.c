#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para exibir uma matriz qualquer
void exibir_matriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Definindo navios como coordenadas
    int navio_vertical[3][2] = {{2,3}, {3,3}, {4,3}};
    int navio_horizontal[3][2] = {{6,5}, {6,6}, {6,7}};

    // Exibindo coordenadas dos navios posicionados manualmente
    printf("Coordenadas do Navio Vertical:\n");
    for (int i = 0; i < 3; i++) {
        printf("(%d, %d)\n", navio_vertical[i][0], navio_vertical[i][1]);
    }

    printf("\nCoordenadas do Navio Horizontal:\n");
    for (int i = 0; i < 3; i++) {
        printf("(%d, %d)\n", navio_horizontal[i][0], navio_horizontal[i][1]);
    }

    printf("\n");

    // Criando o tabuleiro 10x10 e inicializando com 0
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Posicionando navios no tabuleiro
    tabuleiro[2][1] = 3; tabuleiro[2][2] = 3; tabuleiro[2][3] = 3; // horizontal
    tabuleiro[0][5] = 3; tabuleiro[1][5] = 3; tabuleiro[2][5] = 3; // vertical
    tabuleiro[5][5] = 3; tabuleiro[6][6] = 3; tabuleiro[7][7] = 3; // diagonal descendo
    tabuleiro[8][1] = 3; tabuleiro[7][2] = 3; tabuleiro[6][3] = 3; // diagonal subindo

    // Exibindo o tabuleiro completo
    printf("Tabuleiro 10x10:\n");
    exibir_matriz(TAM_TABULEIRO, TAM_TABULEIRO, tabuleiro);

    // Criando matrizes para habilidades especiais
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Preenchendo padrão Cone
    cone[0][2] = 1;
    cone[1][1] = cone[1][2] = cone[1][3] = 1;
    for (int j = 0; j < TAM_HABILIDADE; j++) {
        cone[2][j] = 1;
    }

    // Preenchendo padrão Cruz
    for (int j = 0; j < TAM_HABILIDADE; j++) {
        cruz[1][j] = 1;
    }
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        cruz[i][2] = 1;
    }

    // Preenchendo padrão Octaedro
    octaedro[0][2] = 1;
    octaedro[1][1] = octaedro[1][2] = octaedro[1][3] = 1;
    octaedro[2][2] = 1;
    octaedro[3][2] = 1;

    // Exibindo habilidades
    printf("Habilidade - Cone:\n");
    exibir_matriz(TAM_HABILIDADE, TAM_HABILIDADE, cone);

    printf("Habilidade - Cruz:\n");
    exibir_matriz(TAM_HABILIDADE, TAM_HABILIDADE, cruz);

    printf("Habilidade - Octaedro:\n");
    exibir_matriz(TAM_HABILIDADE, TAM_HABILIDADE, octaedro);

    return 0;
}
