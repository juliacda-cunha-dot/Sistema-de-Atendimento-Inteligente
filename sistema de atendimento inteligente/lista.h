#ifndef LISTA_H
#define LISTA_H

#include "atendimento.h"

typedef struct NoLista {
    Atendimento dado;
    struct NoLista* proximo;
} NoLista;

void inicializar_lista(NoLista** topo);
void inserir_lista(NoLista** topo, Atendimento a);
void listar_historico(NoLista* topo);
void buscar_por_nome(NoLista* topo, const char* nome);
void buscar_por_prioridade(NoLista* topo, int prioridade);
void liberar_lista(NoLista** topo);

#endif