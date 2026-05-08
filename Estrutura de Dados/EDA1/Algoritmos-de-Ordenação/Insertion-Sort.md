Pertence a: [[Algoritmos-de-Ordenação]]
Tags: #eda1 #conteudo 

---
# Insertion Sort (Ordenação por Inserção)

Também é simples e funciona construindo a lista ordenada "um item por vez".

- **Analogia:** Organizar cartas de baralho na sua mão. Você pega uma carta de cada vez da mesa. Para cada carta nova, você a "insere" na posição correta da sua mão (que já está ordenada), empurrando as cartas maiores para a direita.

## Como Funciona

1. Assume que o primeiro item (i=0) já está "ordenado".

2. Começa pelo segundo item (i=1). Pega esse item (a "chave").

3. Compara a chave com os itens antes dela (para a esquerda).

4. Se a chave for menor, "empurra" o item da esquerda para a direita, abrindo espaço.

5. Repete até encontrar a posição correta (um item menor ou o início) e "insere" a chave ali.

- Velocidade: O(n2) (Pior Caso). Mas é O(n) (Rápido) se o array estiver quase ordenado.

- Espaço: O(1) (In-place).

- Estável: Sim.

        | 3 | 1 | 2 | 7 | 0 |  // Vetor não ordenado
        | 3 | - | - | - | - |  // Compara o segundo com o primeiro
        | 1 | 3 | - | - | - |  // Compara o terceiro com os anteriores
        | 1 | 2 | 3 | - | - |  // Compara o quarto com os anteriores
        | 1 | 2 | 3 | 7 | - |  // Compara o quinto com os anteriores
        | 0 | 1 | 2 | 3 | 7 |  // Vetor ordenado
