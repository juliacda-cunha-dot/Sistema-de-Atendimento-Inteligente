#ifndef HASH_H
#define HASH_H

#include "atendimento.h"

#define TAM_HASH 10

typedef struct NoHash {
    Atendimento dado;
    struct NoHash* proximo;
} NoHash;

typedef struct {
    NoHash* tabela[TAM_HASH];
} TabelaHash;

void inicializar_hash(TabelaHash* h);
int funcao_hash(const char* categoria);
void inserir_hash(TabelaHash* h, Atendimento a);
void buscar_por_categoria_hash(TabelaHash* h, const char* categoria);
void liberar_hash(TabelaHash* h);

#endif