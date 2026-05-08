Pertence a: [[Algoritmos-de-Ordenação]]
Tags: #eda1 #conteudo 

---
# Merge Sort (Ordenação por Intercalação)

Um algoritmo clássico de "Dividir e Conquistar". É extremamente eficiente e confiável.

- **Analogia:** Você tem uma pilha gigante de provas desordenadas.

  **1. Dividir:** Você divide a pilha em duas. Divide de novo. E de novo, até ter várias pilhas de 1 prova (que estão, por definição, "ordenadas").

  **2. Conquistar (Intercalar):** Você começa a juntar (intercalar) as pilhas de volta. Você pega duas pilhas de 1, olha a nota de cada topo, e cria uma nova pilha ordenada de 2. Pega duas pilhas de 2 e cria uma de 4. Repete até ter uma única pilha gigante, totalmente ordenada.

---

## Como Funciona

**1.** Divide o array recursivamente ao meio até que cada sub-array tenha 1 elemento.

**2.** Chama a função "merge" (intercalar) para juntar dois sub-arrays ordenados em um único array maior e ordenado. Isso requer um array temporário.

- Velocidade: O(nlogn) (Rápido, em todos os casos).

- Espaço: O(n) (Alto. Precisa de um array auxiliar).

- Estável: Sim.

                    | 6 | 9 | 7 | 1 | 8 | 4 | 5 | 0 |

            | 6 | 9 | 7 | 1 |   <------->   | 8 | 4 | 5 | 0 |

        | 6 | 9 | <---> | 7 | 1 |       | 8 | 4 | <---> | 5 | 0 |

      | 6 |<->| 9 |   | 7 |<->| 1 |   | 8 |<->| 4 |   | 5 |<->| 0 |

        | 6 | 9 | <---> | 1 | 7 |       | 4 | 8 | <---> | 0 | 5 |

            | 1 | 6 | 7 | 9 |   <------->   | 0 | 4 | 5 | 8 |

                    | 0 | 1 | 4 | 5 | 6 | 7 | 8 | 9 |
