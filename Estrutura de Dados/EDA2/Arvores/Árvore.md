Pertence a: [[EDA2]]
Tags: #eda2 #hub

---
# Árvore

Uma árvore é um conjunto de *registros* organizados de forma hierárquica de modo que os elementos se ligam apenas entre níveis hierárquicos adjacente..

``` mermaid
graph TD
	A[ ] --> B[ ]
	A --> C[ ]
	A --> D[ ]
	
	B --> B1[ ]
	B --> B2[ ]
	
	C --> C1[ ]
	C --> C2[ ]
	C --> C3[ ]
	
	D --> D1[ ]
	
	B2 --> B3[ ]
	
	C2 --> C21[ ]
	
	D1 --> D11[ ]
```

Os elementos que constituem uma árvore são:

- Dados de cada nó 
- Ligações entre nós 
- Hierarquia de forma

## Conceitos

Os registros da árvore são chamados de *nós* ou *células*, e a ligação entre eles, *arestas*.
Há apenas um nó no nível zero, chamado *raiz*.

Dado um nó X:

- Um nó *adjacente* a x é um nó ligado a x por uma aresta.
- Os nós adjacentes a x em um nível inferior são chamados *filhos*, e no nível superior, pai (único).
- Dados dois nós *a* e *b* quaisquer, os nós adjacentes entre a e b é chamado de *caminho*, e a quantidade de nós percorridos (sem contar a) é dita *distância* de a e b.

``` mermaid
graph TD
	o[a] --> a[ ]
	o --- b[ ]
	o --- c[ ]
	
	a --- a21[ ]
	a --> a22[ ]
	
	a21 --- a211[ ]
	a21 --- a212[ ]
	
	a22 --> a221[ ]
	
	a221 --> a2211[b]
	
	b --- b2[ ]
	
	c --- c21[ ]
	c --- c22[ ]
	c --- c23[ ]
	
	c21 --- c211[ ]
	
	c23 --- c231[ ]
	c23 --- c232[ ]
```
Distância de ab = 4.

Um nó que não possui filho é chamado de *folha*, e o único que não possui paz é raiz.
A *altura* de um nó é a maior distância a uma folha descente, e a *profundidade* é a distância à raiz.
A *Altura da Árvore* é a altura da raiz.

## Tipos

- [[Árvore-Binária]]
- 
## Relacionado

assunto assunto assunto assunto 