#ifndef PILHA_FILA_H
#define PILHA_FILA_H

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *criar_pilha();
celula *criar_fila();

void add_pilha(celula *p, int x);
int rm_pilha(celula *p);

void add_fila(celula *p, int x);
int rm_fila(celula *p);

void destroi_pilha(celula *p);
void destroi_fila(celula *p);

#endif