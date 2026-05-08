Pertence a: [[EDA2]]
Tags: #eda2 #conteudo #p1 

---
# HEAP

Um **Heap** (especificamente um Heap Binário) é uma estrutura de dados baseada em árvores que resolve um problema muito específico: **manter o controle do maior (ou menor) elemento de um conjunto de forma extremamente eficiente.**

Na prática, o Heap é a estrutura padrão usada para implementar uma **Fila de Prioridade** (`FP`). Em uma fila normal, o primeiro a entrar é o primeiro a sair. Em uma fila de prioridade, o elemento com _maior prioridade_ (o maior valor, neste caso) sai primeiro, independentemente de quando ele entrou.

## A Regra de Ouro (Propriedade do Heap)

Para ser considerado um Heap, a árvore binária precisa respeitar duas regras estritas:

1. **Formato (Árvore Quase Completa):** A árvore deve ser preenchida nível por nível, da esquerda para a direita. Não pode haver "buracos".
    
2. **Ordem (Propriedade Max-Heap):** O valor de um nó pai deve ser **sempre maior ou igual** ao valor de seus filhos. Isso garante que o maior elemento de toda a árvore estará sempre na raiz (posição 0). Existe também o Min-Heap, onde a lógica é invertida.

## O "Pulo do Gato": Árvore dentro de um Vetor

Se você reparar no seu código `FP *cria_heap(int tam)`, você não usa ponteiros `esq` e `dir` como usava na Árvore Rubro-Negra. Você usa um simples vetor (`f->dado`).

Como a árvore do Heap não tem buracos, nós podemos mapear as posições da árvore diretamente para índices de um vetor usando matemática básica. Se um nó está no índice `i`:

- **Pai:** Fica no índice `(i - 1) / 2`
    
- **Filho à Esquerda:** Fica no índice `2*i + 1`
    
- **Filho à Direita:** Fica no índice `2*i + 2`

É por isso que as suas funções `sobe_no_heap` e `desce_no_heap` usam essas continhas de multiplicação e divisão em vez de ponteiros. É muito mais rápido e economiza memória.

## 1. Inserção

``` mermaid
graph TB
	32 --> 21
	32 --> 25
	
	21 --> 18
	21 --> 10
	
	18 --> 14
	18 --> 16
	
	10 --> 3
	10 --> 7
	
	25 --> 19
	25 --> 8
	
	19 --> 12
	19 --> 15
```

``` c
void insere(FP *f, int x){
	if(f->tam <= f->n){
		f->dado = realloc(2 * f->tam * sizeof(int));
		f->tam *= 2;
	}
	f->dado[f->n] = x;
	f->n++;
	sobe_no_heap(f);
}

void sobe_no_heap(FP *fp){
	int i = fp->n - 1, pai = (i-1)/2;
	
	while(i > 0 && fp->dado[pai] < fp->dado[i]){
		troca(&fp->dado[pai], fp->dado + i);
		i = pai;
		pai = (i-1)/2;	
	}
}

void troca(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
```
---
## 2. Remoção

``` mermaid
graph TD
	32 --> 21
	32 --> 25
	
	21 --> 18
	21 --> 10
	
	18 --> 14
	18 --> 16
	
	10 --> 3
	10 --> 7
	
	25 --> 19
	25 --> 8
	
	19 --> 12
	19 --> 15
```

``` mermaid
graph TD
	25 --> 21
	25 --> 19
	
	21 --> 18
	21 --> 10
	
	18 --> 14
	18 --> 16
	
	10 --> 3
	10 --> 7
	
	
	19 --> 15
	19 --> 8
	
	15 --> 12
	
	32
	
	style 32 fill:red, color:black
	
	classDef verde fill:green, color:black
	class 25,19,15 verde
```
``` c
int extrai_maximo(FP *f){
	if(f->n > 0){
		int max = f->dado[0];
		f->dado[0] = f->dado[f->n-1]
		f->n--;
		desce_no_heap(f);
		return max;
	}
}

void desce_no_heap(FP *f){
	int i = 0, esq = 1, dir = 2, maior_filho;
	
	while(esq < f->n){
		maior_filho = esq;
		if(dir < f->n && f->dado[dir] > f->dado[esq]){
			maior_filho = dir;
		}
		if(f->dado[i] < f->dado[maior_filho]){
			troca(&f->dado[i], &f->dado[maior_filho]);
			i = maior_filho;
			esq = 2*i + 1;
			dir = esq + 1;
		}
		else return;
	}
}
```

``` c
FP *cria_heap(int tam){
	FP *f = malloc(sizeof(FP));
	f->dado = malloc(tam * sizeof(int));
	f->n = 0;
	return f;
}

void destroi_fila(FP *f){
	free(f->dado);
	free(f);
}
```

### Análise de Complexidade

|**Operação**|**Tempo**|**O que acontece na prática?**|
|---|---|---|
|**Encontrar o Máximo**|$O(1)$|Como manda a Regra da Ordem, o maior elemento de toda a árvore estará sempre na raiz (posição 0 do vetor).|
|**Inserção (`sobe_no_heap`)**|$O(\log n)$|Você coloca no final e o elemento vai "borbulhando" para cima até encontrar alguém maior que ele ou chegar na raiz.|
|**Remoção (`desce_no_heap`)**|$O(\log n)$|Você tira a raiz, bota o último elemento no topo e ele vai "descendo" até os filhos serem menores que ele.|
|**Construção (Heapify)**|$O(n)$|Consegue transformar um array totalmente desordenado em um Heap em tempo linear.|

- **Complexidade de Espaço:** $O(n)$. O único espaço de memória consumido é estritamente o tamanho do vetor para guardar os números em si. Essa abordagem o torna muito mais rápido e econômico em termos de memória, pois você não gasta espaço armazenando endereços de ponteiros.