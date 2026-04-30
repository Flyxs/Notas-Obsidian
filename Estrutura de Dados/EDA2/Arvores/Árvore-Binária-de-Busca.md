Pertence a: [[Árvore]]
Tags: #eda2 #conteudo

---
# Árvore Binária de Busca

Uma *Árvore Binária de Busca (ABB*) é uma árvore binária tal que, para um dado nó x qualquer,
$$e <= x <= d,$$
para todo nó e pertence à sub-árvore esquerda x e todo nó *d* pertence à sub-árvore direita de x.

Exemplo:
``` mermaid
graph TD
	15 --> 7
	15 --> 28
	
	7 --> 3
	7 --> 12
	
	3 --> -1
	3 --> 5
	
	5 --> 4
	
	12 --> 10
	12 --> 14
	
	10 --> 11
	
	
	28 --> 20
	28 --> 30
	
	20 --> 17
	20 --> 23
	
	30 --> 29
	30 --> 40
```
### TAD

``` c
typedef struct celula{
	int dado;
	celula *esq, *dir;
}celula;

celula *cria_abb(int x);
void destroi_abb(celula *raiz);
celula *buscar(celula *raiz, int x);
celula *inserir(celula *raiz, int x);
celula *remover(celula *raiz, int x);

celula *cria_abb(int x){
	celula *raiz = malloc(sizeof(celula));
	raiz -> dado = x;
	raiz -> esq = raiz -> dir = NULL;
	return raiz;
}

void destroi_abb(celula *raiz){
	if (raiz != NULL){
		destroi_abb(raiz -> esq);
		destroi_abb(raiz -> dir);
		free();
	}
}

celula *inserir(celula *raiz, int x){
	if(raiz != NULL) {
		if(x < raiz -> valor) {
			raiz -> esq = inserir(raiz -> esq, x);
		}
		else if(x > raiz -> valor){
			raiz -> dir = inserir(raiz -> dir, x);
		}
	}
	else{
		return cria_abb(x);
	}
}
```

#### Remoção

Para remover um nó x:

1. Se um dos filhos de x for `NULL`,  ^dc6a41
	- Remove X
	- Conecta o outro filho de x no pai de x

2. Se ambos os filhos de x forem diferentes de `NULL` 
	* Troca os valores do nó x com seu sucessor (ou antecessor).
	* Remove o sucessor (ou antecessor) - Caso 1([[#^dc6a41]])

``` c 
celula *remove(celula *raiz, int x){
	if (raiz != NULL) {
	
		# Busca
		if(x < raiz -> valor){
			raiz -> esq = remove(raiz -> esq, x);
		}
		else if(x > raiz -> valor){
			raiz -> dir = remove(raiz -> dir, x);
		}
		
		# caso 1
		else if (raiz -> esq == NULL) {
			celula *p = raiz -> dir;
			free(raiz);
			return p;
		}
		else if (raiz -> dir == NULL) {
			celula *p = raiz -> esq;
			free(raiz);
			return p;
		}
		
		# caso 2
		else remove_sucessor(raiz);
	}
	return raiz;
}
```
``` c
void remove_sucessor(celula *raiz) {
	celula *pai = raiz;
	celula *filho = raiz -> dir;
	while(filho -> esq != NULL) {
		pai = filho;
		filho = filho -> esq;
	}
	// filho aponta para o sucessor da raiz
	raiz -> dado = filho -> dado;
	if (pai == raiz) pai -> dir = filho -> dir;
	else pai -> esq = filho -> dir;
	free(filho);
}
```
