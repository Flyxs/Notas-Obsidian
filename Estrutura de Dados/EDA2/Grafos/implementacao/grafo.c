#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

grafo *criar_grafo(int n, int tipo) {
    grafo *g = malloc(sizeof(grafo));
    g -> n = n;
    g -> tipo = tipo;
    g -> matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g -> matriz[i] = calloc(n, sizeof(int));
    }
    return g;
}

void add_aresta(grafo *g, int x, int y, int valor) {
    if (g -> tipo == 0) {
        g -> matriz[x][y] = 1;
        g -> matriz[y][x] = 1;
    }
    else if (g -> tipo == 1) g -> matriz[x][y] = 1;

    else if (g -> tipo == 2) {
        g -> matriz[x][y] = valor;
        g -> matriz[y][x] = valor;
    }
    else if (g -> tipo == 3) g -> matriz[x][y] = valor;
}

void rm_aresta(grafo *g, int x, int y) {
    if (g -> tipo == 0) {
        g -> matriz[x][y] = 0;
        g -> matriz[y][x] = 0;
    }
    else if (g -> tipo == 1) g -> matriz[x][y] = 0;
}

void imprimir_grafo(grafo *g) {
    if (g -> tipo == 0) {
        for (int i = 0; i < g -> n; i++) {
            for (int j = i; j < g -> n; j++) {
                if (g -> matriz[i][j] == 1) printf("%d <---> %d\n", i, j);
            }
        }
    }
    else if (g -> tipo == 1) {
        for (int i = 0; i < g -> n; i++) {
            for (int j = 0; j < g -> n; j++) {
                if (g -> matriz[i][j] == 1) printf("%d ---> %d\n", i, j);
            }
        }
    }
    else if (g -> tipo == 2) {
        for (int i = 0; i < g -> n; i++) {
            for (int j = i; j < g -> n; j++) {
                if (g -> matriz[i][j] != 0) printf("%d <-%d-> %d\n", i, g -> matriz[i][j], j);
            }
        }
    }
    else if (g -> tipo == 3) {
        for (int i = 0; i < g -> n; i++) {
            for (int j = 0; j < g -> n; j++) {
                if (g -> matriz[i][j] != 0) printf("%d -%d-> %d\n", i, g -> matriz[i][j], j);
            }
        }
    }
}

grafo *excluir_grafo(grafo *g) {
    if (g == NULL) return NULL;

    for (int i = 0; i < g -> n; i++) {
        free(g -> matriz[i]);
    }
    free(g -> matriz);
    free(g);

    return NULL;
}
