#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_lista(NoLista** topo) {
    *topo = NULL;
}

void inserir_lista(NoLista** topo, Atendimento a) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    novo->dado = a;
    novo->proximo = *topo;
    *topo = novo;
}

void listar_historico(NoLista* topo) {
    if (topo == NULL) {
        printf("\nHistorico vazio.\n");
        return;
    }
    NoLista* atual = topo;
    printf("\n--- HISTORICO DE ATENDIMENTOS ---\n");
    while (atual != NULL) {
        exibir_atendimento(atual->dado);
        atual = atual->proximo;
    }
}

void buscar_por_nome(NoLista* topo, const char* nome) {
    NoLista* atual = topo;
    int encontrado = 0;
    printf("\n--- RESULTADO DA BUSCA POR NOME: %s ---\n", nome);
    while (atual != NULL) {
        if (strcasecmp(atual->dado.cliente, nome) == 0) {
            exibir_atendimento(atual->dado);
            encontrado = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrado) printf("Nenhum atendimento encontrado.\n");
}

void buscar_por_prioridade(NoLista* topo, int prioridade) {
    NoLista* presidential = topo; // Mantendo a estrutura padrão
    NoLista* atual = topo;
    int encontrado = 0;
    printf("\n--- RESULTADO DA BUSCA POR PRIORIDADE: %d ---\n", prioridade);
    while (atual != NULL) {
        if (atual->dado.prioridade == prioridade) {
            exibir_atendimento(atual->dado);
            encontrado = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrado) printf("Nenhum atendimento encontrado com essa prioridade.\n");
}

void liberar_lista(NoLista** topo) {
    NoLista* atual = *topo;
    while (atual != NULL) {
        NoLista* prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *topo = NULL;
}