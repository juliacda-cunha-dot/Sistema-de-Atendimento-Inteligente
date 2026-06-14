#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

NoArvore* inicializar_arvore() {
    return NULL;
}

NoArvore* inserir_arvore(NoArvore* raiz, Atendimento a) {
    if (raiz == NULL) {
        NoArvore* novo = (NoArvore*)malloc(sizeof(NoArvore));
        novo->dado = a;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    
    if (a.id < raiz->dado.id) {
        raiz->esquerda = inserir_arvore(raiz->esquerda, a);
    } else if (a.id > raiz->dado.id) {
        raiz->direita = inserir_arvore(raiz->direita, a);
    }
    return raiz;
}

NoArvore* buscar_arvore(NoArvore* raiz, int id) {
    if (raiz == NULL || raiz->dado.id == id) {
        return raiz;
    }
    
    if (id < raiz->dado.id) {
        return buscar_arvore(raiz->esquerda, id);
    }
    return buscar_arvore(raiz->direita, id);
}

void liberar_arvore(NoArvore* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}