#ifndef ARVORE_H
#define ARVORE_H

#include "atendimento.h"

typedef struct NoArvore {
    Atendimento dado;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

NoArvore* inicializar_arvore();
NoArvore* inserir_arvore(NoArvore* raiz, Atendimento a);
NoArvore* buscar_arvore(NoArvore* raiz, int id);
void liberar_arvore(NoArvore* raiz);

#endif