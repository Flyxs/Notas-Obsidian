Pertence a: [[Grafos]]
Tags: #eda2 #md2 #p2

---
# BFS e DFS

## Busca em Largura (BFS)

*Ideia Central*: processar os vértices por níveis, começando por aqueles vértices mais próximos à origem e deixando os mais distantes para depois.

Começamos por um vértice inicial. A partir dele, continuamos caminhando pelo grafo enquanto ainda existirem vértices adjacentes que não foram visitados. Em cada passo, verificamos os vértices adjacentes ao vértice atual. Se houver algum adjacente que ainda não foi visitado, escolhemos um deles e seguimos para esse vértice, marcando-o como visitado.

Um vértice é considerado *final* quando todos os seus vértices adjacentes já foram visitados. Quando isso acontece, não é mais possível avançar a partir dele.

```pseudo
BFS(G, s) 
para cada v em G 
	visitado[v] ← falso 
	
criar fila Q 

visitado[s] ← verdadeiro 
enfileirar(Q, s) 

enquanto Q não vazia 
		u ← desenfileirar(Q) 
		imprimir(u) 
		para cada v em Adj[u] 
			se visitado[v] = falso 
			
				visitado[v] ← verdadeiro 
				enfileirar(Q, v)
```
> Custo Total O(|V| + |E|)

## Busca Em Profundidade (DFS)

*Ideia*: explorar o grafo indo o mais fundo possível a partir de um vértice inicial, seguindo por um caminho até não ser mais possível avançar. Somente depois disso voltamos para tentar outros caminhos ainda não explorados. 

Funcionamento: Começamos por um vértice inicial e o marcamos como visitado. A partir dele, escolhemos um de seus vértices adjacentes que ainda não tenha sido visitado e seguimos para esse novo vértice. Em seguida, repetimos o mesmo processo: a cada passo, avançamos para um adjacente não visitado do vértice atual. 

Assim, a busca em profundidade tenta sempre aprofundar o caminho atual antes de considerar outras alternativas. 

Um vértice é considerado final quando todos os seus vértices adjacentes já foram visitados. Quando isso acontece, não é mais possível continuar a partir dele. Nesse caso, voltamos para o vértice anterior e verificamos se ainda existe algum outro adjacente não visitado. Se existir, seguimos por esse novo caminho. Se não existir, voltamos novamente. 

Esse processo continua até que todos os vértices alcançáveis a partir do vértice inicial tenham sido visitados.

```pesudo
DFS(G, s) 
para cada u em V(G) faça 
	visitado[u] ← falso 
	
cria pilha P 
empilha(P, s) 

enquanto P não vazia faça 
	u ← desempilha(P) 
	
	se visitado[u] = falso então
		visitado[u] ← verdadeiro 
		imprime(u) 
		
	para cada v em Adj[u] faça 
		se visitado[v] = falso então 
		empilha(P, v)
```
> O(|V| + |E|)
