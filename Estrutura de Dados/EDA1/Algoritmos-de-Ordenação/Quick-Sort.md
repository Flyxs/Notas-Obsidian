Pertence a: [[Algoritmos-de-Ordenação]]
Tags: #eda1 #conteudo 

---
# Quick Sort (Ordenação Rápida)

O algoritmo "padrão-ouro" da ordenação. Também usa "Dividir e Conquistar" e é, na prática, o mais rápido para a maioria dos casos.

- Analogia: Colocar alunos em fila por altura.

    1. **Pivô:** Você escolhe um aluno (o "pivô").

    2. **Particionar:** Você reorganiza a fila: todos os alunos mais baixos que o pivô ficam à sua esquerda, e os mais altos à sua direita. O pivô agora está magicamente em sua posição final correta!

    3. **Recursão:** Você repete o processo (escolhe um novo pivô) para a "fila da esquerda" e para a "fila da direita".

## Como Funciona

**1.** Escolhe um elemento para ser o "pivô" (ex: o último).

**2.** Chama a função "particiona", que reorganiza o array. No final, o pivô está na posição j.

**3.** Chama recursivamente a qsort para a parte à esquerda do pivô (e até j-1).

**4.** Chama recursivamente a qsort para a parte à direita do pivô (j+1 até d).

- **Velocidade**: O(nlogn) (Caso Médio e Melhor). O(n2) (Pior Caso, muito raro em boas implementações).

- **Espaço:** O(logn) (Baixo, usado pela pilha de recursão).

- **Estável:** Não.

        j k                       p
        | 2 | 1 | 7 | 4 | 6 | 3 | 5 |

             j k                  p
        | 2 | 1 | 7 | 4 | 6 | 3 | 5 |

                 j k              p
        | 2 | 1 | 7 | 4 | 6 | 3 | 5 |

                  j   k           p
        | 2 | 1 | 7 | 4 | 6 | 3 | 5 |

                      j   k       p
        | 2 | 1 | 4 | 7 | 6 | 3 | 5 |

                      j       k   p
        | 2 | 1 | 4 | 7 | 6 | 3 | 5 |

                          j      k p
        | 2 | 1 | 4 | 3 | 6 | 7 | 5 |

                          j       p
        | 2 | 1 | 4 | 3 | 5 | 7 | 6 |

---

         j k          p          p         j k  p
        | 2 | 1 | 4 | 3 |      | 5 |      | 7 | 6 |

             j k      p          p          j  k p
        | 2 | 1 | 4 | 3 |      | 5 |      | 7 | 6 |

                 j k  p          p             p
        | 2 | 1 | 4 | 3 |      | 5 |      | 6 | 7 |

                  j  k p         p              p
        | 2 | 1 | 4 | 3 |      | 5 |      | 6 | 7 |

                      p          p             p
        | 2 | 1 | 3 | 4 |      | 5 |      | 6 | 7 |

---

         j k  p               p          p              p
        | 2 | 1 |       | 3 | 4 |      | 5 |      | 6 | 7 |

          j  k p              p          p              p
        | 2 | 1 |       | 3 | 4 |      | 5 |      | 6 | 7 |

              p               p          p              p
        | 1 | 2 |       | 3 | 4 |      | 5 |      | 6 | 7 |
---

        | 1 | 2 | 3 | 4 | 5 | 6 | 7 |  // vetor ordenado
