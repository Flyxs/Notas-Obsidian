Pertence a: [[Árvore]]
Tags: #eda2 #conteudo 

---
# Árvore Binária de Busca Rubro Negro Esquerdista

É uma *ABB* auto-balanceável, ou seja, com garantia de altura logarítmica.

Há 5 regras de existência de uma *ABB-RNE*:

1. Todo nó é *vermelho* ou preto.
2. A raiz é preta.
3. As folhas são ``NULL``'s e tem a cor preta.
4. Se um nó é *vermelho*, então:
	*  Seus filhos são pretos.
	* É filho esquerdo.
5. Para qualquer nó da ABB-RNE, a quantidade de nós pretos a qualquer folha descendente é a mesma
	* não se conta o próprio nó.
	* essa propriedade chama-se *altura-negra* do nó.

``` mermaid
graph TD
	26 --> 17
	26 --> 41
	
	17 --> 14
	17 --> 21
	
	14 --> 10
	14 --> 16
	
	10 --> 7
	10 --> 12
	
	7 --> 3
	
	16 --> 15
	
	21 --> 19
	21 --> 23
	
	19 --> 18
	
	
	41 --> 30
	41 --> 47
	
	30 --> 28
	30 --> 38
	
	38 --> 35
	
	
	classDef vermelho color:red
	class 17,10,3,15,18,30,35 vermelho

```

considere *bh* a altura negra de uma ABB-RNE.

1. Quantos nós, no mínimo, tem uma ABB-RNE com altura negra bh? **$2^{bh} - 1$ nós**
2. Se *h* é a altura da árvore, então $h/2 <= bh <= h$

Então, para uma ABB-RNE qualquer com n nós, $h <= 2log(n+1)$

## Correção na ABBRNE
### Condições para Correção

1. Caso 1: Subida de Cor
``` c
ehPreto(r) && ehVerm(r -> esq) && ehVerm(r -> dir)
```
2. Caso 2: Rotação à Esquerda
``` c
ehPreto(r) && ehPreto(r -> esq) && ehVerm(r -> dir)
```
3. Caso 3: Rotação à Esquerda
``` c
ehPreto(r) && ehVerm(r -> esq) && ehVerm(r -> esq -> esq)
```

### Operações de Correção

1. Caso 1: Subida de Cor
``` mermaid
graph TD
	r1[r] --> a1[a]
	r1 --> b1[b]
	
	r2[r] --> a2[a]
	r2 --> b2[b]
	
	classDef vermelho color:red
	class a1,b1,r2 vermelho
```
2. Caso 2: Rotação à Esquerda
``` mermaid
graph TD
	r1[r] --> x1[x]
	r1 --> a1[a]
	a1 --> x2[y]
	a1 --> x3[z]
	
	a2[a] --> r2[r]
	a2 --> x4[z]
	r2 --> x5[x]
	r2 --> x6[y]
	
	classDef vermelho color:red
	class a1,r2 vermelho
```
3. Caso 3: Rotação à Direita
``` mermaid
graph TD
	r1[r] --> a1[a]
	r1 --> z1[z]
	a1 --> x1[x]
	a1 --> y1[y]
	
	a2[a] --> x2[x]
	a2 --> r2[r]
	r2 --> y2[y]
	r2 --> z2[z] 
	
	classDef vermelho color:red
	class a1,r2 vermelho
```

## TAD

``` c
typedef struct celula{
	int dado;
	celula *esq, *dir;
	int cor;     //0 = preto; 1 = vermelho
} celula;

celula *insere_aabbrne(celula *raiz, int x){
	if(raiz != NULL){
	
		//Busca
		if(x < raiz -> dado){
			raiz -> esq = insere_abbrne(raiz -> esq, x);
		}
		else if(x > raiz -> dado){
			raiz -> dir = insere_abbrne(raiz -> dir, x);
		}
		
		//Correção
		if(ehPreto(raiz -> esq) && ehVerm(raiz -> dir)){
			raiz = rotacao_a_esquerda(raiz);
		}
		if(ehPreto(raiz) && ehVerm(raiz -> esq) && ehVerm(raiz -> esq ->esq)){
			raiz = rotacao_a_direita(raiz);
		}
		if(ehPreto(raiz) && ehVerm(raiz -> esq) && ehVerm(raiz -> dir)){
			sobe_cor(raiz);
		}
		return raiz;
	}
	else{
		celula *novo = malloc(sizeof(celula));
		novo -> esq = novo -> dir = NULL;
		novo -> dado = x;
		novo -> cor = 1;
		return novo;
	}
}
```
``` c
void sobe_cor(celula *raiz){
	raiz -> cor = 1;
	raiz -> esq -> cor = raiz -> dir -> cor = 0;
}

celula *roatacao_a_esquerda(celula *raiz){
	celula *a = raiz -> dir;
	a ->  cor = raiz -> cor;
	raiz -> cor = 1;
	celula *beta = a -> esq;
	a -> esq = raiz;
	raiz -> dir = beta;
	return a;
}

celula *rotacao_a_direita(celula *raiz){
	celula *a = raiz -> esq;
	a -> cor = 1;
	celula *beta = a -> dir;
	a -> dir = raiz;
	raiz -> esq = beta;
	return a;
}
```