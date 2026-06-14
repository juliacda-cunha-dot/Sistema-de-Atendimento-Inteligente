#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_hash(TabelaHash* h) {
    for (int i = 0; i < TAM_HASH; i++) {
        h->tabela[i] = NULL;
    }
}

int funcao_hash(const char* categoria) {
    int soma = 0;
    for (int i = 0; categoria[i] != '\0'; i++) {
        soma += categoria[i];
    }
    return soma % TAM_HASH;
}

void inserir_hash(TabelaHash* h, Atendimento a) {
    int indice = funcao_hash(a.categoria);
    
    NoHash* novo = (NoHash*)malloc(sizeof(NoHash));
    novo->dado = a;
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;
}

void buscar_por_categoria_hash(TabelaHash* h, const char* categoria) {
    int indice = funcao_hash(categoria);
    NoHash* atual = h->tabela[indice];
    int encontrado = 0;
    
    printf("\n--- RESULTADO DA BUSCA HASH POR CATEGORIA: %s ---\n", categoria);
    while (atual != NULL) {
        if (strcasecmp(atual->dado.categoria, categoria) == 0) {
            exibir_atendimento(atual->dado);
            encontrado = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrado) {
        printf("Nenhum atendimento encontrado nesta categoria.\n");
    }
}

void liberar_hash(TabelaHash* h) {
    for (int i = 0; i < TAM_HASH; i++) {
        NoHash* atual = h->tabela[i];
        while (atual != NULL) {
            NoHash* prox = atual->proximo;
            free(atual);
            atual = prox;
        }
        h->tabela[i] = NULL;
    }
}