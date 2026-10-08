# 🧮 CMathPrograms - Métodos Numéricos e Computação Científica em C

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Domain](https://img.shields.io/badge/Domain-Numerical%20Analysis-red.svg)
![Mathematics](https://img.shields.io/badge/Field-Scientific%20Computing-purple.svg)
![Status](https://img.shields.io/badge/Status-Conclu%C3%ADdo-brightgreen.svg)

## 📌 Visão Geral
O **CMathPrograms** é uma coleção de algoritmos de **Cálculo Numérico e Análise Numérica** desenvolvidos em **C puro**, voltados para a resolução precisa de problemas matemáticos contínuos através de métodos computacionais.

O repositório reúne implementações eficientes para duas das maiores áreas do cálculo computacional: **isolamento e determinação de raízes de funções transcendentais/algébricas** e **resolução de sistemas lineares algébricos de ordem $N$**, tanto por métodos diretos quanto iterativos.

---

## 🚀 Métodos e Algoritmos Implementados

### 1. Zeros de Funções Reais (Cálculo de Raízes)
- 🔹 **Método da Bisseção (`Biseccoes.c`)**: Método intervalar robusto baseado no Teorema de Bolzano com garantia incondicional de convergência.
- 🔹 **Método da Falsa Posição (`FalsePositionMethod.c`)**: Algoritmo de interpolação linear (Regula Falsi) que acelera a convergência em relação à bisseção.
- 🔹 **Método de Newton-Raphson (`MetodoNewton.c`)**: Método de aproximação tangencial com taxa de convergência quadrática rápida, utilizando a derivada analítica da função.
- 🔹 **Método das Secantes (`MetodoSecante.c`)**: Variante do método de Newton que substitui a derivada analítica por uma aproximação de diferenças finitas.

### 2. Solução Direta de Sistemas Lineares
- 🔹 **Eliminação de Gauss Simples (`GausSimples.c`)**: Triangularização da matriz de coeficientes com substituição retroativa.
- 🔹 **Gauss com Pivotamento Parcial (`GaussParcial.c`)**: Troca dinâmica de linhas para minimizar erros de arredondamento causados por pivôs pequenos.
- 🔹 **Gauss com Pivotamento Completo (`GaussCompleto.c`)**: Pivotamento duplo (linhas e colunas) garantindo a máxima estabilidade numérica.
- 🔹 **Decomposição LU (`DecomposicaoLU.c`)**: Fatoração de matrizes em $A = L \times U$ para resolução acelerada de sistemas com múltiplos vetores de termos independentes.
- 🔹 **Método de Gauss-Jordan (`GaussJordan.c`)**: Transformação direta do sistema na matriz identidade correspondente.
- 🔹 **Sistemas Triangulares (`Sistemastriangulares.c`)**: Resolução direta por substituições retroativas e sucessivas.

### 3. Solução Iterativa de Sistemas Lineares
- 🔹 **Método de Gauss-Jacobi (`GaussJacobi.c`)**: Solução iterativa com atualização síncrona dos vetores incógnitas a cada passo.
- 🔹 **Método de Gauss-Seidel (`GaussSeidel.c`)**: Atualização imediata em cadeia dos valores calculados na iteração corrente, acelerando a taxa de convergência com controle de tolerância de erro $\epsilon$.

---

## 🛠️ Tecnologias e Ferramentas
- **Linguagem**: C (C99 / C11)
- **Compilador**: GCC / Clang / MinGW
- **Bibliotecas Standard**: `<stdio.h>`, `<stdlib.h>`, `<math.h>` (compilado com flag `-lm`)

---

## 📂 Estrutura do Repositório
```plaintext
CMathPrograms/
├── Biseccoes.c                  # Método da Bisseção
├── FalsePositionMethod.c        # Método da Falsa Posição (Regula Falsi)
├── MetodoNewton.c               # Método de Newton-Raphson
├── MetodoSecante.c              # Método das Secantes
├── GausSimples.c                # Eliminação Gaussiana sem pivô
├── GaussParcial.c               # Eliminação Gaussiana com pivô parcial
├── GaussCompleto.c              # Eliminação Gaussiana com pivô completo
├── DecomposicaoLU.c             # Fatoração LU de matrizes
├── GaussJordan.c                # Algoritmo de Gauss-Jordan
├── Sistemastriangulares.c       # Resolução direta de matrizes triangulares
├── GaussJacobi.c                # Método iterativo de Jacobi
└── GaussSeidel.c                # Método iterativo de Gauss-Seidel
```

---

## ⚙️ Como Executar os Programas

### Pré-requisitos
- Compilador GCC instalado no sistema.

### Compilação e Execução de Qualquer Método
Para compilar qualquer um dos algoritmos, execute no terminal:
```bash
# Exemplo compilando o Método de Gauss-Seidel:
gcc -Wall -O2 GaussSeidel.c -o GaussSeidel -lm
./GaussSeidel
```
```bash
# Exemplo compilando o Método de Newton-Raphson:
gcc -Wall -O2 MetodoNewton.c -o MetodoNewton -lm
./MetodoNewton
```
O programa solicitará interativamente via console a ordem da matriz, os coeficientes e a precisão desejada.

---

## 👨‍💻 Autor
Desenvolvido por **Luca Samuel dos Santos** ([@LucaS4nt0s](https://github.com/LucaS4nt0s)).
