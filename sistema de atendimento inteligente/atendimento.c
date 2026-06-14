#include "atendimento.h"
#include <stdio.h>
#include <string.h>

Atendimento criar_atendimento(int id, const char* cliente, const char* categoria, int prioridade, int tempo) {
    Atendimento a;
    a.id = id;
    strcpy(a.cliente, cliente);
    strcpy(a.categoria, categoria);
    a.prioridade = prioridade;
    a.tempo_estimado = tempo;
    strcpy(a.status, "aberto");
    return a;
}

void exibir_atendimento(Atendimento a) {
    printf("[%d] Cliente: %-15s | Cat: %-10s | Prio: %d | Tempo: %3d min | Status: %s\n",
           a.id, a.cliente, a.categoria, a.prioridade, a.tempo_estimado, a.status);
}