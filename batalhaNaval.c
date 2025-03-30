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
void criarHabilidadeLosango(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int centro_linha, int centro_coluna);

void lerCoordenadas(int *linha, int *coluna, const char *mensagem) {
    printf("%s", mensagem);
    scanf("%d %d", linha, coluna);
    // Validação básica
    while (*linha < 0 || *linha >= TAM_TABULEIRO || *coluna < 0 || *coluna >= TAM_TABULEIRO) {
        printf("Coordenadas inválidas! Tente novamente (linha coluna): ");
        scanf("%d %d", linha, coluna);
    }
}

int lerInteiro(const char* mensagem) {
    int valor;
    char buffer[100]; // Para limpar entradas inválidas
    
    while (1) {
        printf("%s", mensagem);
        
        if (scanf("%d", &valor) == 1) {
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            return valor;
        } else {
            printf("Entrada inválida! Digite um número.\n");
            // Limpa o buffer para evitar loop infinito
            scanf("%s", buffer);
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int losango[TAM_HABILIDADE][TAM_HABILIDADE];
    int opcao, tipo_navio, tipo_habilidade, linha, coluna;
    bool sucesso;

    // Inicializações
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeLosango(losango);

    printf("=== BATALHA NAVAL - MODO INTERATIVO ===\n");

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Posicionar navio\n");
        printf("2. Usar habilidade\n");
        printf("3. Visualizar tabuleiro\n");
        printf("4. Sair\n");
        
        opcao = lerInteiro("Escolha: ");

        switch (opcao) {
            case 1: // Posicionar navio
                printf("\n=== TIPO DE NAVIO ===\n");
                printf("1. Horizontal (tamanho %d)\n", TAM_NAVIO);
                printf("2. Vertical (tamanho %d)\n", TAM_NAVIO);
                printf("3. Diagonal / (tamanho %d)\n", TAM_NAVIO);
                printf("4. Diagonal \\ (tamanho %d)\n", TAM_NAVIO);
                
                tipo_navio = lerInteiro("Escolha: ");
                linha = lerInteiro("Digite a linha inicial (0-9): ");
                coluna = lerInteiro("Digite a coluna inicial (0-9): ");

                switch (tipo_navio) {
                    case 1: sucesso = posicionarNavioReto(tabuleiro, linha, coluna, true); break;
                    case 2: sucesso = posicionarNavioReto(tabuleiro, linha, coluna, false); break;
                    case 3: sucesso = posicionarNavioDiagonal(tabuleiro, linha, coluna, true); break;
                    case 4: sucesso = posicionarNavioDiagonal(tabuleiro, linha, coluna, false); break;
                    default:
                        printf("Opção inválida!\n");
                        sucesso = false;
                }
                printf(sucesso ? "Navio posicionado com sucesso!\n" : "Falha ao posicionar navio!\n");
                break;

            case 2: // Usar habilidade
                printf("\n=== HABILIDADES ===\n");
                printf("1. Cone (triângulo)\n");
                printf("2. Cruz (+)\n");
                printf("3. Losango (octaedro)\n");
                
                tipo_habilidade = lerInteiro("Escolha: ");
                linha = lerInteiro("Digite a linha central (0-9): ");
                coluna = lerInteiro("Digite a coluna central (0-9): ");

                switch (tipo_habilidade) {
                    case 1: aplicarHabilidade(tabuleiro, cone, linha, coluna); break;
                    case 2: aplicarHabilidade(tabuleiro, cruz, linha, coluna); break;
                    case 3: aplicarHabilidade(tabuleiro, losango, linha, coluna); break;
                    default: printf("Opção inválida!\n");
                }
                break;

            case 3: // Visualizar tabuleiro
                printf("\n=== TABULEIRO ===\n");
                exibirTabuleiro(tabuleiro);
                break;

            case 4:
                printf("Encerrando o jogo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

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
bool posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
    int linha, int coluna, 
    bool diagonal_positiva) {
// Verifica se todas as posições são válidas
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

// Cria matriz de habilidade losango (octaedro)
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
