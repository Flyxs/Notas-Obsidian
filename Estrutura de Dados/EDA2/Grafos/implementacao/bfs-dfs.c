#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "pilha-fila.h"

void bfs(grafo *g, int start) {
    int *visitados = calloc(g -> n, sizeof(int));
    visitados[start] = 1;

    celula *fila = criar_fila();
    add_fila(fila, start);

    while (fila -> prox != NULL) {
        for (int i = 0; i < g -> n; i++) {
            if (g -> matriz[fila -> prox -> dado][i] != 0 && visitados[i] != 1) {
                add_fila(fila, i);
                visitados[i] = 1;
            }
        }
        printf("%d ", rm_fila(fila));
    }
    printf("\n");

    destroi_fila(fila);
    free(visitados);
}

void dfs(grafo *g, int start) {
    int *visitados = calloc(g -> n, sizeof(int));

    celula *pilha = criar_pilha();
    visitados[start] = 1;
    add_pilha(pilha, start);

    while (pilha -> prox != NULL) {
        int temp = pilha -> prox -> dado;
        printf("%d ", rm_pilha(pilha));

        for (int i = 0; i < g -> n; i++) {
            if (g -> matriz[temp][i] != 0 && visitados[i] != 1) {
                add_pilha(pilha, i);
                visitados[i] = 1;
            }
        }
    }
    printf("\n");

    destroi_pilha(pilha);
    free(visitados);
}