Pertence a: [[TED e PED]]
Tags:

---
# Conversão de Bases

## Ideia Geral

Conversão de bases = representar o mesmo número em sistemas diferentes:

- Base 2 -> binário (0, 1)
- Base 10 -> decimal  (0 - 9)
- Base 16 -> hexadecimal ( 0 - 9 + A - F)

## Conversões Principais

### Decimal para Binário

Divisão sucessiva por 2.

Exemplo: 
$$
(13)10 -> (13)2
$$

```
13 ÷ 2 = 6 resto 1  
6 ÷ 2 = 3 resto 0  
3 ÷ 2 = 1 resto 1  
1 ÷ 2 = 0 resto 1
```

resultado:

$$
(13)10​=(1101)2​
$$
>[!tip]
>Ler o resto de baixo para cima

### Binário para Decimal

Multiplica cada Bit por potência de 2.

Exemplo:

$$
(1101)2
=1×2^3+1×2^2+0×2^1+1×2^0
=8+4+0+1=13
$$

### Binário para Hexadecimal

Agrupa de **4 em 4 bits (da direita pra esquerda)**.

Exemplo:
$$
(11010101)2​
$$
1101 0101
- 1101 = D
- 0101 = 5

Resultado:
$$
(11010101)2​=(D5)16​
$$

### Hexadecimal para Binário

Cada digito vira 4 bits.

Exemplo:
$$
(F0A)16​
$$
```
F = 1111
0 = 0000
A = 1010
```
Resultado:
$$
(F0A)16​=(111100001010)2​
$$

### Hexadecimal para Decimal

Multiplica por potências de 16.

Exemplo:
$$
(32)10​
$$
```
32 ÷ 16 = 2 resto 0
```
Resultado:
$$
(32)10​=(20)16​
$$
