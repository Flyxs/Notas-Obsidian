Pertence a: [[MD2]]
Tags:

---
# Divisibilidade e Primos

1. Primos e Números Compostos
2. Divisibilidade, MDC, MMC e Algoritmos.
3. Aplicações.

## Primos e Números Compostos 

Definição básica
Um número natural n>1 pode ser classificado em:
### Número Primo

- possui exatamente dois divisores positivos.
	- 1 e ele mesmo

Exemplos:
- 2, 3, 5, 7, 11, 13, 17, ...

### Números Compostos

- Possui mais de dois divisores

Exemplos:
- 4, 6, 8, 9, 10, 12, 14, 15, ...

>[!warning]
>O número 1 não é primo nem composto por que possui apenas um divisor

---
### Teorema Fundamental da Aritmética

Todo número inteiro maior que 1 pode ser escrito de forma única como produto de números primos.

Exemplos:
- 60 = 2² * 3 * 5
- 84 = 2² * 3 * 7
- 100 = 2² * 5²

### Como saber se um número é primo

Para verificar se n é primo:

- Teste divisões por números até $\sqrt{n}$​

Exemplo: verificar 29
- √29 ≈ 5.38 → testa 2, 3, 5
- Nenhum divide → **29 é primo**

>[!warning] Propriedades Importantes
>2 é o **único primo par**
Todo número composto pode ser **decomposto em primos**
Existem **infinitos primos** (como vimos antes)

## Divisibilidade, MDC, MMC e Algoritmos

### Definição

Dizemos que:

$$
a | b
$$

(se lê: “a divide b”) quando:

Existe um inteiro $k$ tal que $b = a⋅k$

