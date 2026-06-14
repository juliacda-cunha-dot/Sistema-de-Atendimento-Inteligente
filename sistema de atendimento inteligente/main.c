#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atendimento.h"
#include "fila.h"
#include "lista.h"
#include "ordenacao.h"
#include "arvore.h"
#include "hash.h"

void menu() {
    printf("\n===== SISTEMA DE ATENDIMENTOS =====\n");
    printf("1  - Cadastrar atendimento\n");
    printf("2  - Atender proximo da fila\n");
    printf("3  - Cancelar atendimento\n");
    printf("4  - Listar fila de espera\n");
    printf("5  - Listar historico\n");
    printf("6  - Buscar por nome do cliente\n");
    printf("7  - Buscar por prioridade\n");
    printf("8  - Buscar por ID usando arvore\n");
    printf("9  - Buscar por categoria usando hash\n");
    printf("10 - Ordenar historico por prioridade (Maior -> Menor)\n");
    printf("11 - Ordenar historico por tempo estimado (Menor -> Maior)\n");
    printf("12 - Exibir estatisticas gerais\n");
    printf("0  - Sair\n");
    printf("Escolha uma opcao: ");
}

void atualizar_status_historico(NoLista* topo, int id, const char* novo_status) {
    NoLista* atual = topo;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            strcpy(atual->dado.status, novo_status);
            return;
        }
        atual = atual->proximo;
    }
}

void exibir_estatisticas(NoLista* topo) {
    int total = 0, atendidos = 0, cancelados = 0, abertos = 0;
    int p1 = 0, p2 = 0, p3 = 0;
    
    NoLista* atual = topo;
    while (atual != NULL) {
        total++;
        if (strcmp(atual->dado.status, "atendido") == 0) atendidos++;
        else if (strcmp(atual->dado.status, "cancelado") == 0) cancelados++;
        else abertos++;
        
        if (atual->dado.prioridade == 1) p1++;
        else if (atual->dado.prioridade == 2) p2++;
        else if (atual->dado.prioridade == 3) p3++;
        
        atual = atual->proximo;
    }
    
    printf("\n--- ESTATISTICAS DO SISTEMA ---\n");
    printf("Total de Atendimentos Cadastrados: %d\n", total);
    printf("Status -> Abertos: %d | Atendidos: %d | Cancelados: %d\n", abertos, atendidos, cancelados);
    printf("Quantidade por Prioridade -> Baixa (1): %d | Media (2): %d | Alta (3): %d\n", p1, p2, p3);
}

int main() {
    Fila minha_fila;
    NoLista* meu_historico;
    NoArvore* minha_arvore;
    TabelaHash minha_hash;
    
    inicializar_fila(&minha_fila);
    inicializar_lista(&meu_historico);
    minha_arvore = inicializar_arvore();
    inicializar_hash(&minha_hash);
    
    int opcao;
    int id_contador = 1;

    do {
        menu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            break;
        }
        getchar(); // Limpa buffer

        if (opcao == 1) {
            char cliente[50], categoria[30];
            int prioridade, tempo;

            printf("Nome do Cliente: ");
            fgets(cliente, 50, stdin);
            cliente[strcspn(cliente, "\n")] = 0;

            printf("Categoria: ");
            fgets(categoria, 30, stdin);
            categoria[strcspn(categoria, "\n")] = 0;

            printf("Prioridade (1-Baixa, 2-Media, 3-Alta): ");
            scanf("%d", &prioridade);
            printf("Tempo Estimado (min): ");
            scanf("%d", &tempo);

            Atendimento novo = criar_atendimento(id_contador++, cliente, categoria, prioridade, tempo);
            
            enfileirar(&minha_fila, novo);
            inserir_lista(&meu_historico, novo);
            minha_arvore = inserir_arvore(minha_arvore, novo);
            inserir_hash(&minha_hash, novo);
            
            printf("Sucesso! Cadastrado com ID: %d\n", novo.id);

        } else if (opcao == 2) {
            Atendimento atendido;
            if (desenfileirar(&minha_fila, &atendido)) {
                printf("Atendendo: %s (ID: %d)\n", atendido.cliente, atendido.id);
                atualizar_status_historico(meu_historico, atendido.id, "atendido");
            } else {
                printf("Fila vazia!\n");
            }

        } else if (opcao == 3) {
            int id_cancela;
            printf("Digite o ID do atendimento a cancelar: ");
            scanf("%d", &id_cancela);
            atualizar_status_historico(meu_historico, id_cancela, "cancelado");
            printf("Status do ID %d alterado para cancelado.\n", id_cancela);

        } else if (opcao == 4) {
            listar_fila(&minha_fila);

        } else if (opcao == 5) {
            listar_historico(meu_historico);

        } else if (opcao == 6) {
            char busca_nome[50];
            printf("Nome para busca: ");
            fgets(busca_nome, 50, stdin);
            busca_nome[strcspn(busca_nome, "\n")] = 0;
            buscar_por_nome(meu_historico, busca_nome);

        } else if (opcao == 7) {
            int prio;
            printf("Prioridade para busca (1-3): ");
            scanf("%d", &prio);
            buscar_por_prioridade(meu_historico, prio);

        } else if (opcao == 8) {
            int id_busca;
            printf("Digite o ID para buscar na Arvore: ");
            scanf("%d", &id_busca);
            NoArvore* resultado = buscar_arvore(minha_arvore, id_busca);
            if (resultado != NULL) {
                printf("\n[ID Encontrado via Arvore]:\n");
                exibir_atendimento(resultado->dado);
            } else {
                printf("ID %d nao encontrado na arvore.\n", id_busca);
            }

        } else if (opcao == 9) {
            char cat_busca[30];
            printf("Digite a Categoria para buscar na Tabela Hash: ");
            fgets(cat_busca, 30, stdin);
            cat_busca[strcspn(cat_busca, "\n")] = 0;
            buscar_por_categoria_hash(&minha_hash, cat_busca);

        } else if (opcao == 10) {
            ordenar_por_prioridade(meu_historico);
            printf("Historico ordenado por prioridade! Selecione a opcao 5 para ver.\n");

        } else if (opcao == 11) {
            ordenar_por_tempo(meu_historico);
            printf("Historico ordenado por tempo estimado! Selecione a opcao 5 para ver.\n");

        } else if (opcao == 12) {
            exibir_estatisticas(meu_historico);
        }

    } while (opcao != 0);

    liberar_fila(&minha_fila);
    liberar_lista(&meu_historico);
    liberar_arvore(minha_arvore);
    liberar_hash(&minha_hash);
    
    printf("Sistema fechado de forma limpa.\n");
    return 0;
}