#include <stdio.h>
#include <stdbool.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


// Constantes do jogo (tabuleiro 10 x 10)
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Funções
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
bool posicionarNavioReto(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal);
bool posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool diagonal_positiva);
bool posicaoValida(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna);

int main() {
    printf("=== Jogo de Batalha Naval - Nivel Aventureiro ===\n\n");
    
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona os navios retos (horizontal/vertical)
    if (!posicionarNavioReto(tabuleiro, 2, 2, true)) {  // Horizontal: linha 2, coluna 2-4
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }
    
    if (!posicionarNavioReto(tabuleiro, 0, 5, false)) {  // Vertical: coluna 5, linhas 0-2
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }
    
    // Posiciona os navios diagonais
    if (!posicionarNavioDiagonal(tabuleiro, 4, 1, true)) {  // Diagonal positiva (/): (4,1), (5,2), (6,3)
        printf("Erro ao posicionar navio diagonal positiva!\n");
        return 1;
    }
    
    if (!posicionarNavioDiagonal(tabuleiro, 1, 7, false)) {  // Diagonal negativa (\): (1,7), (2,6), (3,5)
        printf("Erro ao posicionar navio diagonal negativa!\n");
        return 1;
    }
    
    // Exibe o tabuleiro
    printf("Tabuleiro (10x10):\n");
    printf("Legenda: 0 = Agua, 3 = Navio\n\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

// Inicializa todas as posições do tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Cabeçalho com números das colunas
    printf("     ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Linhas do tabuleiro com números das linhas
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se uma posição específica está dentro do tabuleiro e é água
bool posicaoValida(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    return (linha >= 0 && linha < TAM_TABULEIRO && 
            coluna >= 0 && coluna < TAM_TABULEIRO && 
            tabuleiro[linha][coluna] == AGUA);
}

// Posiciona um navio reto (horizontal ou vertical)
bool posicionarNavioReto(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    // Verifica se todas as posições do navio são válidas
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (horizontal) {
            if (!posicaoValida(tabuleiro, linha, coluna + i)) {
                return false;
            }
        } else {
            if (!posicaoValida(tabuleiro, linha + i, coluna)) {
                return false;
            }
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (horizontal) {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    
    return true;
}

// Posiciona um navio diagonal (positiva: / ou negativa: \)
bool posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool diagonal_positiva) {
    // Verifica se todas as posições do navio são válidas
    for (int i = 0; i < TAM_NAVIO; i++) {
        int linha_atual = linha + i;
        int coluna_atual = diagonal_positiva ? coluna + i : coluna - i;
        
        if (!posicaoValida(tabuleiro, linha_atual, coluna_atual)) {
            return false;
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        int linha_atual = linha + i;
        int coluna_atual = diagonal_positiva ? coluna + i : coluna - i;
        
        tabuleiro[linha_atual][coluna_atual] = NAVIO;
    }
    
    return true;
}