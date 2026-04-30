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
2. 