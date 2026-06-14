# Sistema de Atendimento Técnico Inteligente

Este projeto consiste em um sistema de terminal desenvolvido em Linguagem C para o gerenciamento, organização e análise de atendimentos técnicos diários. O sistema utiliza estruturas de dados dinâmicas e avançadas para otimizar operações de busca, ordenação e controle de fluxo.

## 🛠️ Tecnologias Utilizadas
- **Linguagem:** C
- **Ambiente de Desenvolvimento:** OnlineGDB / GCC Terminal

## 📂 Organização dos Arquivos (TADs)
O código está modularizado seguindo os princípios de Tipo Abstrato de Dados (TAD):
- `main.c`: Fluxo principal e menu interativo.
- `atendimento.h` / `atendimento.c`: Estrutura base dos dados do atendimento.
- `fila.h` / `fila.c`: Fila dinâmica (FIFO) para controle da ordem de espera.
- `lista.h` / `lista.c`: Lista encadeada dinâmica para armazenamento do histórico.
- `ordenacao.h` / `ordenacao.c`: Algoritmo Bubble Sort aplicado à lista encadeada.
- `arvore.h` / `arvore.c`: Árvore Binária de Busca (ABB) para indexação rápida por ID.
- `hash.h` / `hash.c`: Tabela Hash com encadeamento para agrupamento por categoria.

Integrantes e Divisão de Responsabilidades

André Huff
atendimento.c, atendimento.h, fila.c, fila.h e o menu do main.c

Júlia C . da Cunha
lista.c, lista.h, ordenacao.c, ordenacao.h, além da Árvore e da Tabela Hash.
Nome do Integrante:André Huff.
Responsabilidade:atendimento.c,atendimento.h,fila.c,fila.h, e o menu main.c
