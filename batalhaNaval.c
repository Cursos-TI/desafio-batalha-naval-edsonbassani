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
bool posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal);

int main() {
    printf("=== Jogo de Batalha Naval - Nivel Novato ===\n\n");
    
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona os navios (1 horizontal e 1 vertical)
    // Coordenadas ajustadas para 10x10 (sem sobreposição)
    if (!posicionarNavio(tabuleiro, 2, 2, true)) {  // Horizontal: linha 2, coluna 2-4
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }
    
    if (!posicionarNavio(tabuleiro, 0, 5, false)) {  // Vertical: coluna 5, linhas 0-2
        printf("Erro ao posicionar navio vertical!\n");
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
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    // Linhas do tabuleiro com números das linhas
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d: ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona um navio no tabuleiro (retorna true se bem sucedido)
bool posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    // Verifica se o navio cabe na posição
    if (horizontal) {
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) {
            return false;
        }
        
        // Verifica se as posições estão livres
        for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
            if (tabuleiro[linha][j] != AGUA) {
                return false;
            }
        }
        
        // Posiciona o navio
        for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
            tabuleiro[linha][j] = NAVIO;
        }
    } else {
        if (linha + TAM_NAVIO > TAM_TABULEIRO) {
            return false;
        }
        
        // Verifica se as posições estão livres
        for (int i = linha; i < linha + TAM_NAVIO; i++) {
            if (tabuleiro[i][coluna] != AGUA) {
                return false;
            }
        }
        
        // Posiciona o navio
        for (int i = linha; i < linha + TAM_NAVIO; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }
    }
    
    return true;
}