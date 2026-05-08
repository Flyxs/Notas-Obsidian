Pertence a: [[EDA2]]
Tags: #eda2 #conteudo #p1

---
# HASH

A Tabela Hash (Tabela de Espalhamento) é uma estrutura de dados que associa **Chaves** a **Valores**. O grande diferencial dela é não precisar percorrer a estrutura (como numa lista) ou descer níveis (como numa árvore) para encontrar um dado. Ela usa matemática básica para descobrir _exatamente_ em qual posição da memória o dado está armazenado.

### 2. A Mágica: A Função de Espalhamento (Hash Function)

A base física de uma Tabela Hash é simplesmente um Array (Vetor) tradicional. A magia acontece na forma como escolhemos os índices desse vetor.

Quando você quer inserir um elemento (por exemplo, a matrícula do aluno `12345`), você passa essa chave por uma **Função Hash**. A função mastiga esse número e cospe um índice válido do seu vetor.

A função mais comum em aulas de C é o operador Módulo (resto da divisão):

$$h(k) = k \bmod M$$

_(Onde $k$ é a chave e $M$ é o tamanho do vetor)._

- **Exemplo:** Se seu vetor tem tamanho 10, e você insere a chave 42.
    
- $42 \bmod 10 = 2$. O número 42 será guardado diretamente no índice `vetor[2]`.
    

### 3. O Problema Inevitável: Colisões

Como o nosso vetor tem um tamanho fixo (ex: 10 posições) e o universo de chaves possíveis é infinito (qualquer número inteiro), eventualmente duas chaves diferentes vão resultar no mesmo índice.

- $42 \bmod 10 = 2$
    
- $72 \bmod 10 = 2$
    

Isso se chama **Colisão**. Uma boa Tabela Hash não é aquela que evita colisões (isso é matematicamente impossível pelo Princípio da Casa dos Pombos), mas sim a que sabe _tratar_ as colisões de forma eficiente.

### 4. Tratamento de Colisões

Existem duas famílias principais para resolver a briga de dois elementos querendo a mesma vaga:

#### A. Encadeamento Separado (Separate Chaining)

Nesta abordagem, o vetor não guarda os elementos em si, mas sim **ponteiros para listas encadeadas**.

- Se o 42 cair no índice 2, você cria um nó e coloca lá.
    
- Se o 72 também cair no índice 2, você simplesmente adiciona ele no final da lista encadeada que já existe no índice 2. * **Vantagem:** A tabela nunca "enche" de verdade (a lista pode crescer infinitamente).
    

#### B. Endereçamento Aberto (Open Addressing)

Aqui não usamos listas. Tudo fica dentro do próprio vetor. Se houver colisão, procuramos o próximo espaço vazio disponível na tabela.

- **Sondagem Linear (Linear Probing):** Bateu no índice 2 e está ocupado? Tenta o 3. Ocupado? Tenta o 4.
    
- **Vantagem:** Não precisa usar ponteiros e `malloc` para criar nós de listas, economizando memória. O vetor se basta.
    

---

### 5. Análise de Complexidade

|**Operação**|**Tempo Médio**|**Tempo Pior Caso**|**O que causa o Pior Caso?**|
|---|---|---|---|
|**Busca**|$O(1)$|$O(n)$|Todas as chaves deram colisão e caíram no mesmo índice (virou uma lista encadeada).|
|**Inserção**|$O(1)$|$O(n)$|Precisa percorrer a lista inteira do índice para inserir no final.|
|**Remoção**|$O(1)$|$O(n)$|Precisa buscar o elemento na lista encadeada do índice afetado.|

---

### 6. Como fica a Estrutura em C (Usando Encadeamento)

Se fôssemos implementar isso no padrão da sua disciplina (com ponteiros), a estrutura física de uma Tabela Hash com Tratamento por Encadeamento ficaria assim:

C

``` c
// O Nó clássico de uma lista encadeada
typedef struct celula {
    int chave;
    int valor;
    struct celula *prox;
} celula;

// A Tabela Hash
typedef struct TabelaHash {
    int tamanho;        // Tamanho máximo do vetor (M)
    celula **vetor;     // Um vetor de ponteiros (Ponteiro duplo, igual você viu na AABBRNE!)
} TabelaHash;
```
