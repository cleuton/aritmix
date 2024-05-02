# Aritmix

Cleuton Sampaio

Aritmix é um programa simples em C++ que analisa uma expressão **infixa**, transforma em **posfixa**, com o uso de uma pilha, e depois a resolve.

É uma demosntração de **análise** de expressões. 

Operadores aritmeticos:
- "+" -> Soma
- "-" -> Subtração
- "*" -> Multiplição
- ":" -> Divisão
- "^" -> Exponenciação

Aceita parentesis

 Casos de teste (já calculados):
 ```
 1+2 = 3
 1--3 = ERRO!
 ((5-3) * (2*3) -1) = 11
 1:(5^(3-2)+1) = 0,166666667
 4^(1:2) = 2
 ((1 + 2) * (6/2)) = ERRO!
 (1+2)^((4-2) * (1+2)) = 729
 -3 *(-2*5)^2 = -300
```

 Uso: aritmix [opcoes]
 Exemplo: ```aritmix (1+2)^((4-2) * (1+2))```
 