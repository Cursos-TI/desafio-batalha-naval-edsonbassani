# Testes do Sistema de Batalha Naval - Nível Novato

<img src="image.png" alt="Tabuleiro Batalha Naval" width="250" style="display: block; margin: 0 auto;" />

## Índice
- 1. Teste de Funcionamento Básico
  - 1.1 Cenário: Posicionamento Padrão de Navios
- 2. Teste de Validação de Posicionamento
- 3. Teste com Valores Extremos
- 4. Guia de Execução de Testes

---
# 1. Teste de Funcionamento Básico

## 1.1 Cenário: Posicionamento Padrão de Navios

**Configuração:**
- Tabuleiro 5x5
- Navio horizontal (tamanho 3) na linha 1, coluna 1
- Navio vertical (tamanho 3) na linha 0, coluna 3

**Saída Esperada:**

***Nível Novato***
```
=== Jogo de Batalha Naval - Nivel Novato ===

Tabuleiro (10x10):
Legenda: 0 = Agua, 3 = Navio

   0 1 2 3 4 5 6 7 8 9 
0: 0 0 0 0 0 3 0 0 0 0 
1: 0 0 0 0 0 3 0 0 0 0 
2: 0 0 3 3 3 3 0 0 0 0 
3: 0 0 0 0 0 0 0 0 0 0 
4: 0 0 0 0 0 0 0 0 0 0 
5: 0 0 0 0 0 0 0 0 0 0 
6: 0 0 0 0 0 0 0 0 0 0 
7: 0 0 0 0 0 0 0 0 0 0 
8: 0 0 0 0 0 0 0 0 0 0 
9: 0 0 0 0 0 0 0 0 0 0 
```

**Verificações:**
1. Navio horizontal ocupa posições (1,1), (1,2), (1,3)
2. Navio vertical ocupa posições (0,3), (1,3), (2,3)
3. As demais posições contêm água (0)


***Nível Aventureiro***
```
=== Jogo de Batalha Naval - Nivel Aventureiro ===

Tabuleiro (10x10):
Legenda: 0 = Agua, 3 = Navio

      0 1 2 3 4 5 6 7 8 9 
 0:  0 0 0 0 0 3 0 0 0 0 
 1:  0 0 0 0 0 3 0 3 0 0 
 2:  0 0 3 3 3 3 3 0 0 0 
 3:  0 0 0 0 0 3 0 0 0 0 
 4:  0 3 0 0 0 0 0 0 0 0 
 5:  0 0 3 0 0 0 0 0 0 0 
 6:  0 0 0 3 0 0 0 0 0 0 
 7:  0 0 0 0 0 0 0 0 0 0 
 8:  0 0 0 0 0 0 0 0 0 0 
 9:  0 0 0 0 0 0 0 0 0 0 
```
**Verificações:**
1. Navio horizontal ocupa posições (2,2), (2,3), (2,4)
2. Navio vertical ocupa posições (0,5), (1,5), (2,5)
3. Navio diagonal positiva (/) ocupa posições (4,1), (5,2), (6,3)
4. Navio diagonal negativa () ocupa posições (1,7), (2,6), (3,5)
5. As demais posições contêm água (0)


***Nível Mestre***
```
=== Jogo de Batalha Naval - Nivel Mestre ===

Tabuleiro (10x10) com Habilidades Especiais:
Legenda: 0 = Agua, 3 = Navio, 5 = Habilidade

      0 1 2 3 4 5 6 7 8 9 
 0:  0 0 0 0 0 3 0 0 0 0 
 1:  0 0 0 5 0 3 0 3 0 0 
 2:  0 0 3 3 3 3 3 0 0 0 
 3:  0 5 5 5 5 3 0 0 0 0 
 4:  0 3 5 5 0 0 0 0 0 0 
 5:  5 5 3 5 5 0 0 5 0 0 
 6:  0 5 5 3 0 0 0 5 0 0 
 7:  0 0 5 0 0 5 5 5 5 5 
 8:  0 0 0 0 0 0 0 5 0 0 
 9:  0 0 0 0 0 0 0 5 0 0 
```
**Verificações:**
1. Navio horizontal ocupa posições (2,2), (2,3), (2,4)
(Linha 2, colunas 2 a 4)

2. Navio vertical ocupa posições (0,5), (1,5), (2,5)
(Coluna 5, linhas 0 a 2)

3. Navio diagonal positiva (/) ocupa posições (4,1), (5,2), (6,3)
(Aumenta linha e coluna simultaneamente)

4. Navio diagonal negativa (\) ocupa posições (1,7), (2,6), (3,5)
(Aumenta linha e diminui coluna)

5. Habilidade Cone afeta área triangular centrada em (3,3)
(Formato: 3 linhas com 1, 3 e 5 posições afetadas respectivamente)

6. Habilidade Cruz afeta área em cruz centrada em (7,7)
(5 posições verticais + 5 horizontais, sobrepostas no centro)

7. Habilidade Octaedro afeta área em losango centrada em (5,2)
(Formato diamante com 5 posições centrais)

8. Água (0) em todas as posições não ocupadas por navios ou habilidades
(Inclui espaços entre navios e fora das áreas de efeito)

Sobreposição controlada:
- Habilidades (5) podem sobrepor água (0)
- Navios (3) NÃO são sobrescritos por habilidades
- Habilidades não se sobrepõem entre si (a menos que seja intencional)

Bordas do tabuleiro:
- Todas as habilidades/navios respeitam os limites 10x10
- Posições inválidas (habilidade próxima à borda) são automaticamente truncadas


**Verificações Adicionais:**
```
Navios:
- Horizontal: (2,2), (2,3), (2,4)
- Vertical: (0,5), (1,5), (2,5)
- Diagonal positiva (/): (4,1), (5,2), (6,3)
- Diagonal negativa (): (1,7), (2,6), (3,5)

Habilidades:
- Cone centrado em (3,3)
- Cruz centrada em (7,7)
- Octaedro centrado em (5,2)

Posições válidas:
- Todas as posições devem estar dentro do tabuleiro 10x10
- Navios não podem se sobrepor
- Habilidades podem sobrepor água e outras habilidades, mas não navios
```

---
# 2. Teste de Validação de Posicionamento

## 2.1 Cenário: Tentativa de posicionamento inválido

**Modificação no código (para teste):**
```c
// Tentar posicionar navio fora do tabuleiro
if (!posicionarNavio(tabuleiro, 3, 3, true)) {
    printf("Erro: Navio horizontal nao cabe nesta posicao!\n");
}
```

**Saída Esperada**
```shell
Erro: Navio horizontal nao cabe nesta posicao!
```

# 3. Teste com Valores Extremos
## 3.1 Cenário: Posicionamento nas bordas do tabuleiro
**Modificação no código (para teste):**
```c
// Navio horizontal no canto inferior esquerdo
posicionarNavio(tabuleiro, 4, 0, true);
// Navio vertical no canto superior direito
posicionarNavio(tabuleiro, 0, 4, false);
```

**Saída Esperada**
```shell
   0 1 2 3 4 
0: 0 0 0 3 3 
1: 0 3 3 3 3 
2: 0 0 0 3 3 
3: 0 0 0 3 0 
4: 3 3 3 0 0 
```

# 4. Guia de Execucão de Testes
## 4.1 Teste manual interativo (compilação)
```shell
gcc batalha_naval.c -o batalha_naval -Wall
./batalha_naval
```

## 4.2 Teste automatizado (Linux/Mac)
```shell
gcc batalha_naval.c -o batalha_naval -Wall
./batalha_naval > saida.txt
diff saida.txt esperado.txt
```
