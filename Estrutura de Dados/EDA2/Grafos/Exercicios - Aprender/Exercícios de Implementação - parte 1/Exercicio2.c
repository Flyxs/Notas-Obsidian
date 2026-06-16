#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
        int n;
        int **matriz;
} grafo;

grafo *criar_grafo(int n) {
        grafo *g = malloc(sizeof(grafo));
        g -> n = n;
        g -> matriz = malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            g -> matriz[i] = malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                g -> matriz[i][j] = 0;
            }
        }
        return g;
}

void inserir_aresta(grafo *g, int u, int v) {
    g -> matriz[u][v] = 1;
}

void imprimir_matriz(grafo *g) {
    for (int i = 0; i < g -> n; i++) {
        int z = 0;
        int k = 0;
        for (int j = 0; j < g -> n; j++) {
            z += g -> matriz[j][i];
            k += g -> matriz[i][j];
        }
        printf("%d %d", z, k);
        printf("\n");
    }
}

grafo *excluir_grafo(grafo *g) {
    if (g == NULL) return NULL;
    for (int i = 0; i < g->n; i++) {
        free(g->matriz[i]);
    }
    free(g->matriz);
    free(g);
    
    return NULL;
}

int main() {
    int V, A;
    scanf("%d %d", &V, &A);

    grafo* garfo = criar_grafo(V);
    
    for (int i = 0; i < A; i++) {
        int V1, V2 = 0;
        scanf("%d %d", &V1, &V2);

        inserir_aresta(garfo, V1, V2);
    }

    imprimir_matriz(garfo);

    
    excluir_grafo(garfo);
    return 0;
}