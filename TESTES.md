# Testes do Sistema de Batalha Naval - Níveis Novato a Mestre

## Índice
- 1. Testes de Funcionamento Básico
  - 1.1 Nível Novato
  - 1.2 Nível Aventureiro
  - 1.3 Nível Mestre
- 2. Testes de Validação
- 3. Testes com Valores Extremos
- 4. Testes Interativos
- 5. Guia de Execução

---

## 1. Testes de Funcionamento Básico

### 1.1 Nível Novato
**Configuração:**
- Tabuleiro 10x10
- 2 navios (1 horizontal, 1 vertical) de tamanho 3

**Saída Esperada:**
=== Jogo de Batalha Naval - Nivel Novato ===

      0  1  2  3  4  5  6  7  8  9
 0:   0  0  0  0  0  3  0  0  0  0
 1:   0  0  0  0  0  3  0  0  0  0
 2:   0  0  3  3  3  3  0  0  0  0
 ...

**Verificações:**
1. Navio horizontal em (2,2)-(2,4)
2. Navio vertical em (0,5)-(2,5)
3. Água (0) nas demais posições

### 1.2 Nível Aventureiro
**Novas Funcionalidades:**
- 4 navios (2 retos + 2 diagonais)

**Saída Esperada:**
=== Jogo de Batalha Naval - Nivel Aventureiro ===

      0  1  2  3  4  5  6  7  8  9
 0:   0  0  0  0  0  3  0  0  0  0
 1:   0  0  0  0  0  0  0  3  0  0
 2:   0  0  3  3  3  3  0  0  0  0
 ...

**Verificações:**
1. Navios diagonais em (4,1)-(6,3) e (1,7)-(3,5)
2. Sem sobreposições

### 1.3 Nível Mestre
**Novas Funcionalidades:**
- Habilidades especiais (Cone, Cruz, Octaedro)

**Saída Esperada:**
=== Jogo de Batalha Naval - Nivel Mestre ===
Legenda: 0=Água, 3=Navio, 5=Habilidade

      0  1  2  3  4  5  6  7  8  9
 0:   0  0  0  5  0  3  0  0  0  0
 1:   0  0  5  5  5  3  0  3  0  0
 ...

**Verificações:
1. Cone centrado em (3,3) - Formato triangular
2. Cruz centrada em (7,7) - Formato +
3. Octaedro centrado em (5,2) - Formato losango

---

## 2. Testes de Validação
### Cenário: Posicionamento inválido
**Entrada:**
Posicionar navio em (8,8) (fora dos limites)

**Saída Esperada:**
"Erro: Posição inválida!"

---

## 3. Testes com Valores Extremos
### Cenário: Posicionamento nas bordas
**Entrada:**
Navio horizontal em (9,0) (canto inferior esquerdo)

**Verificação:**
Navio deve aparecer em (9,0)-(9,2) sem erros

---

## 4. Testes Interativos
### Fluxo Completo:
1. Menu principal com 4 opções
2. Posicionamento manual de navios
3. Aplicação de habilidades
4. Visualização do tabuleiro a qualquer momento

**Exemplo:**
1. Escolha "1" (Posicionar navio)
2. Selecione tipo "3" (Diagonal /)
3. Digite posição "4 1"
4. Confirme no tabuleiro as posições (4,1)-(6,3)

---

## 5. Guia de Execução
### Teste Manual:
```bash
gcc batalha_naval.c -o jogo -Wall
./jogo
```
### Teste Automatizado:
```
./jogo > saida.txt
```

```
diff saida.txt esperado.txt
```

### Verificações Rápidas:
- Navios não se sobrepõem
- Habilidades respeitam bordas
- Entradas inválidas são rejeitadas

