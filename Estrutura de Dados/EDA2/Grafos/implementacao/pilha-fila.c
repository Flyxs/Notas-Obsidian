#include <stdio.h>
#include <stdlib.h>
#include "pilha-fila.h"

celula *criar_pilha() {
    celula *p = malloc(sizeof(celula));
    p -> prox = NULL;
    return p;
}

celula *criar_fila() {
    celula *f = malloc(sizeof(celula));
    f -> prox = NULL; 
    return f;
}

void add_pilha(celula *p, int x) {
    celula *novo = malloc(sizeof(celula));
    novo -> prox = p -> prox;
    novo -> dado = x;
    p -> prox = novo;
}

void add_fila(celula *f, int x) {
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = NULL;

    celula *atual = f;
    while (atual -> prox != NULL) {
        atual = atual -> prox;
    }
    atual -> prox = novo;
}

int rm_pilha(celula *p) {
    if (p -> prox == NULL) return -1;
    celula *lixo = p -> prox;
    p -> prox = lixo -> prox;
    int y = lixo -> dado;
    free(lixo);
    return y;
}

int rm_fila(celula *f) {
    if (f -> prox == NULL) return -1;
    
    celula *lixo = f -> prox;
    int y = lixo -> dado;
    f -> prox = lixo -> prox;
    free(lixo);
    
    return y;
}

void destroi_pilha(celula *p) {
    while (p -> prox != NULL) rm_pilha(p);
    free(p);
}

void destroi_fila(celula *f) {
    while (f -> prox != NULL) rm_fila(f);
    free(f);
}