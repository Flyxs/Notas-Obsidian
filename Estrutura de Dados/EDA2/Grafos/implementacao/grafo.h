#ifndef GRAFO_H
#define GRAFO_H

typedef struct grafo {
    int n;
    int tipo;  // 0 ou 1 -> 0 não direcionado, 1 direcionado
    int **matriz;
} grafo;

grafo *criar_grafo(int n, int tipo);

void add_aresta(grafo *g, int x, int y, int z);
void rm_aresta(grafo *g, int x, int y);

void imprimir_grafo(grafo *g);

grafo *excluir_grafo(grafo *g);

void bfs(grafo *g, int start);
void dfs(grafo *g, int start);



#endif