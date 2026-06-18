#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "pilha-fila.h"

void pausar() {
    printf("\n\nPressione ENTER para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar(); 
}

int main() {
    system("clear");
    int V, A;

    printf("Escolha a quantidade de vértices(V) e arestas(A): ");
    scanf("%d %d", &V, &A);
    printf("\n");

    int tipo;
    printf("Escolha o tipo de grafo ([0]Não direcionado [1]Direcionado [2]Não Direcionado Ponderado [3]Direcionado Ponderado): ");
    scanf("%d", &tipo);
    printf("\n");

    grafo *gra = criar_grafo(V, tipo);

    printf("Coloque as arestas: \n");
    if (gra -> tipo < 2) {
        for (int i = 0; i < A; i++) {
            int V1, V2;
            scanf("%d %d", &V1, &V2);

            add_aresta(gra, V1, V2, 0);
        }
    }
    else {
        for (int i = 0; i < A; i++) {
            int V1, V2, V3;
            scanf("%d %d %d", &V1, &V2, &V3);

            add_aresta(gra, V1, V2, V3);
        }
    }

    while (1){
        system("clear");
        printf("Total de Vértices = %d \nTotal de Arestas = %d", V, A);
        printf("\n\n============================================================================================\n\n");

        int escolha;
        printf("O que gostaria de fazer: \n[1]Imprimir o grafo \n[2]Imprimir BFS \n[3]Imprimir DFS \n[0]Sair \n");
        scanf("%d", &escolha);
        printf("\n");

        if (escolha == 0) {
            printf("Programa finalizado!\n");
            excluir_grafo(gra);
            break;
        }

        else if (escolha == 1) imprimir_grafo(gra);

        else if (escolha == 2) {
            int start;
            printf("Por onde gostária de começar? (0 a %d) \n", V - 1);
            scanf("%d", &start);
            printf("\n\n");
            bfs(gra, start);
        }

        else if (escolha == 3) {
            int start;
            printf("Por onde gostária de começar? (0 a %d) \n", V - 1);
            scanf("%d", &start);
            printf("\n\n");
            dfs(gra, start);
        }

        else printf("Escolha Inválida!\n");

        pausar();
    }


    return 0;
}