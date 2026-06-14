#ifndef FILA_H
#define FILA_H

#include "atendimento.h"

typedef struct NoFila {
    Atendimento dado;
    struct NoFila* proximo;
} NoFila;

typedef struct {
    NoFila* frente;
    NoFila* tras;
} Fila;

void inicializar_fila(Fila* f);
int fila_vazia(Fila* f);
void enfileirar(Fila* f, Atendimento a);
int desenfileirar(Fila* f, Atendimento* a_retorno);
void listar_fila(Fila* f);
void liberar_fila(Fila* f);

#endif