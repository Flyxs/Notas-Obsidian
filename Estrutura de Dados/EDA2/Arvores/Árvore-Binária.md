Pertence a: [[Árvore]]
Tags: #eda2 #conteudo 

---
# Árvore Binária

É uma árvore cujos nós possuem, no máximo, 2 filhos.

``` mermaid
graph TD
	o[ ] --> a[ ]
	o --> b[ ]
	
	a --> a21[ ]
	a --> a22[ ]
	
	b --> b21[ ]
	b --> b22[ ]
	
	a21 --> a211[ ]
	a21 --> a212[ ]
	
	a22 --> a221[ ]
	a22 --> a222[ ]
	
	b21 --> b211[ ]
	b21 --> b212[ ]
	
	b22 --> b221[ ]
	b22 --> b222[ ]
```

Suponha um AB com *n nós*. Então, há:

- n níveis, no máximo.
``` mermaid
graph TD
	o[ ] --> a[ ]
	o[ ] --> null1[null]
	a --> a1[ ]
	a --> null2[null]
	a1 --> a11[ ]
	a1 --> null3[null]
	a11 --> a111[ ]
	a11 --> null4[null]
```
Árvore degenerada

- ⌈log n⌉ + 1 níveis, no máximo.
``` mermaid
graph TD
	o[ ] --> a[ ]
	o --> b[ ]
	
	a --> a21[ ]
	a --> a22[ ]
	
	b --> b21[ ]
	b --> b22[ ]
	
	a21 --> a211[ ]
	a21 --> a212[ ]
	
	a22 --> a221[ ]
	a22 --> a222[ ]
	
	b21 --> b211[ ]
	b21 --> b212[ ]
	
	b22 --> b221[ ]
	b22 --> b222[ ]
```
Árvore Completa

Em um nível K, há, no máximo 2^k

Dada uma AB com m níveis. Então, há: 
- m nós, no mínimo
``` mermaid
graph TD
	o[ ] --> a[ ]
	o[ ] --> null1[null]
	
	a --> null2[null]
	a --> a1[ ]
	
	a1 --> a11[ ]
	a1 --> null3[null]
	
	a11 --> null4[null]
	a11 --> a111[ ]
	
```

- 2^n - 1 nós, no máximo

``` mermaid
graph TD
	o[ ] --> a[ ]
	o --> b[ ]
	
	a --> a21[ ]
	a --> a22[ ]
	
	b --> b21[ ]
	b --> b22[ ]
	
	a21 --> a211[ ]
	a21 --> a212[ ]
	
	a22 --> a221[ ]
	a22 --> a222[ ]
	
	b21 --> b211[ ]
	b21 --> b212[ ]
	
	b22 --> b221[ ]
	b22 --> b222[ ]
```

## Percursos Padrões em Árvores Binárias

### 1. Em profundidade

``` mermaid
graph TD
	o[4] --> a[7]
	o --> b[-2]
	
	a --> a21[2]
	a --> a22[3]
	
	b --> b21[5]
	b --> b22[10]
	
	a21 --> a211[1]
	a21 --> a212[6]
	
	a22 --> a221[4]
	
	b21 --> b211[12]
	
	b22 --> b221[0]
	b22 --> b222[9]
```

1.1 - Pré Ordem

4 -> 7 -> 2 -> 1 -> 6 -> 3 -> 4 -> 8 -> -2 -> 5 -> 12 -> 10 -> 0 -> 9

1.2 - Em Ordem 

1 -> 2 -> 7 -> 3 -> 8 -> 4 -> 4 -> 12 -> 5 -> -2 -> 0 -> 10 -> 9

1.3 - Pós Ordem

1 -> 6 -> 2 -> 8 -> 4 -> 3 -> 7 -> 15 -> 5 -> 0 -> 9 -> 10 -> -2 -> 4

#### Implementação

``` c
typedef struct celula{
	int dado;
	struct celula *esq, *dir;
}celula;

void preordem(celula *raiz){
	if(raiz != NULL) {
		printf("%d", raiz -> dado);
		preordem(raiz -> esq);
		preordem(raiz -> dir);
	}
}

void emordem(celula *raiz){
	if(raiz != NULL){
		emordem(raiz -> esq);
		printf("%d", raiz -> dado);
		emordem(raiz -> dir);
	}
}

void posordem(celula *raiz){
	if(raiz != NULL){
		posordem(raiz -> esq);
		posordem(raiz -> dir);
		printf("%d", raiz -> dado);
	}
}
```

### 2. Em Largura
``` mermaid
graph TD
	4 --> 2
	4 --> 7
	
	2 --> 0
	2 --> 8
	
	8 --> 9
	
	7 --> 3
	7 --> 1
	
	3 --> 10
```
4 -> 2 -> 7 -> 0 -> 8 -> 3 -> 1 -> 9 -> 10

#### Implementação

``` c
typedef struct celula{
	int dado;
	struct celula *esq, *dir;
}celula;

void largura(celula *raiz){
	fila *f = criar_fila();
	enfileira(f,raiz);
	
	while(!fila_vazia(f)){
		raiz = desinfileira(f);
		printf("%d", raiz -> dado);
		
		if(raiz -> esq != NULL) enfileira(f, raiz -> esq);
		if(raiz -> dir != NULL) enfileira(f, raiz -> dir);
	}
}
```

### Altura

``` c
int altura(celula *raiz) {
	if(raiz != NULL){
		int he = altura(raiz -> esq);
		int hd = altuta(raiz -> dir);
		
		if(he>hd) return he+1;
		else return hd+1;
	}
	else return -1;
}
```
