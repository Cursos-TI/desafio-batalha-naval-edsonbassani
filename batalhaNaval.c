#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


// Constantes do jogo
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Funções
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
bool posicaoValida(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna);  // ADICIONE ESTA LINHA
bool posicionarNavioReto(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal);
bool posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool diagonal_positiva);
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int centro_linha, int centro_coluna);

int main() {
    printf("=== Jogo de Batalha Naval - Nivel Mestre ===\n\n");
    
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona os navios (2 retos e 2 diagonais)
    posicionarNavioReto(tabuleiro, 2, 2, true);   // Horizontal
    posicionarNavioReto(tabuleiro, 0, 5, false);  // Vertical
    posicionarNavioDiagonal(tabuleiro, 4, 1, true);  // Diagonal positiva
    posicionarNavioDiagonal(tabuleiro, 1, 7, false); // Diagonal negativa
    
    // Matrizes para as habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    // Cria os padrões das habilidades
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);
    
    // Aplica as habilidades ao tabuleiro (coordenadas definidas no código)
    aplicarHabilidade(tabuleiro, cone, 3, 3);      // Cone centrado em (3,3)
    aplicarHabilidade(tabuleiro, cruz, 7, 7);      // Cruz centrada em (7,7)
    aplicarHabilidade(tabuleiro, octaedro, 5, 2);  // Octaedro centrado em (5,2)
    
    // Exibe o tabuleiro
    printf("Tabuleiro (10x10) com Habilidades Especiais:\n");
    printf("Legenda: 0 = Agua, 3 = Navio, 5 = Habilidade\n\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

/**
 * Verifica se uma posição é válida para colocar navio ou habilidade.
 * @param tabuleiro Matriz do tabuleiro
 * @param linha Linha a ser verificada
 * @param coluna Coluna a ser verificada
 * @return true se a posição é válida (dentro do tabuleiro e é água), false caso contrário
 */
bool posicaoValida(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se está dentro dos limites do tabuleiro
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        return false;
    }
    
    // Verifica se a posição está livre (água) ou pode ser sobrescrita por habilidade
    // (Permite sobrepor habilidades, mas não navios)
    if (tabuleiro[linha][coluna] != AGUA && tabuleiro[linha][coluna] != HABILIDADE) {
        return false;
    }
    
    return true;
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

// Cria matriz de habilidade Cone (formato triangular apontando para baixo)
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica para formar um cone (triângulo)
            if (j >= (TAM_HABILIDADE/2 - i) && j <= (TAM_HABILIDADE/2 + i) && i <= TAM_HABILIDADE/2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade Cruz (formato de cruz)
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica para formar uma cruz
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade Octaedro (formato de losango)
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica para formar um losango
            int dist = abs(i - centro) + abs(j - centro);
            if (dist <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica uma habilidade ao tabuleiro, centrada nas coordenadas especificadas
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int centro_linha, int centro_coluna) {
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = centro_linha - offset + i;
            int coluna = centro_coluna - offset + j;
            
            // Verificação crucial usando posicaoValida
            if (posicaoValida(tabuleiro, linha, coluna) && habilidade[i][j] == 1) {
                tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }
}
