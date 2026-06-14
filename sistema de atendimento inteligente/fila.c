#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar_fila(Fila* f) {
    f->frente = NULL;
    f->tras = NULL;
}

int fila_vazia(Fila* f) {
    return (f->frente == NULL);
}

void enfileirar(Fila* f, Atendimento a) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->dado = a;
    novo->proximo = NULL;
    
    if (fila_vazia(f)) {
        f->frente = novo;
    } else {
        f->tras->proximo = novo;
    }
    f->tras = novo;
}

int desenfileirar(Fila* f, Atendimento* a_retorno) {
    if (fila_vazia(f)) return 0;
    
    NoFila* aux = f->frente;
    *a_retorno = aux->dado;
    
    f->frente = f->frente->proximo;
    if (f->frente == NULL) {
        f->tras = NULL;
    }
    
    free(aux);
    return 1;
}

void listar_fila(Fila* f) {
    if (fila_vazia(f)) {
        printf("\nNenhum atendimento na fila de espera.\n");
        return;
    }
    NoFila* atual = f->frente;
    printf("\n--- FILA DE ESPERA ---\n");
    while (atual != NULL) {
        exibir_atendimento(atual->dado);
        atual = atual->proximo;
    }
}

void liberar_fila(Fila* f) {
    Atendimento temp;
    while (desenfileirar(f, &temp));
}