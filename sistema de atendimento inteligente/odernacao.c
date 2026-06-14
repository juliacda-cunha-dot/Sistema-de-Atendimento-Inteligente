#include "ordenacao.h"
#include <stddef.h>

void ordenar_por_prioridade(NoLista* topo) {
    if (topo == NULL) return;
    int trocou;
    NoLista* atual;
    NoLista* ultimo = NULL;

    do {
        trocou = 0;
        atual = topo;

        while (atual->proximo != ultimo) {
            if (atual->dado.prioridade < atual->proximo->dado.prioridade) {
                Atendimento temp = atual->dado;
                atual->dado = atual->proximo->dado;
                atual->proximo->dado = temp;
                trocou = 1;
            }
            atual = atual->proximo;
        }
        ultimo = atual;
    } while (trocou);
}

void ordenar_por_tempo(NoLista* topo) {
    if (topo == NULL) return;
    int trocou;
    NoLista* atual;
    NoLista* ultimo = NULL;

    do {
        trocou = 0;
        atual = topo;

        while (atual->proximo != ultimo) {
            if (atual->dado.tempo_estimado > atual->proximo->dado.tempo_estimado) {
                Atendimento temp = atual->dado;
                atual->dado = atual->proximo->dado;
                atual->proximo->dado = temp;
                trocou = 1;
            }
            atual = atual->proximo;
        }
        ultimo = atual;
    } while (trocou);
}