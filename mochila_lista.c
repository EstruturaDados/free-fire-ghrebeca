#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mochila_lista.h"
#include "utils.h" // inclui a funcao lerInt

void listarItensLista(No *inicio) {
    if (!inicio) {
        printf("\nMochila vazia!\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA ---\n");
    printf("--------------------------------------------------------------\n");
    printf("%-25s | %-20s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("--------------------------------------------------------------\n");

    No *aux = inicio;
    while (aux) {
        printf("%-25s | %-20s | %-10d\n", aux->dados.nome, aux->dados.tipo, aux->dados.quantidade);
        aux = aux->proximo;
    }

    printf("--------------------------------------------------------------\n");
}

void adicionarItemLista(No **inicio) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro de memória!\n");
        return;
    }

    printf("Nome do item: ");
    scanf(" %[^\n]", novo->dados.nome);
    printf("Tipo do item: ");
    scanf(" %[^\n]", novo->dados.tipo);
    novo->dados.quantidade = lerInt("Quantidade: ");
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *aux = *inicio;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo;
    }

    printf("\nItem adicionado com sucesso!\n");
}

void removerItemLista(No **inicio) {
    if (!*inicio) {
        printf("\nMochila vazia!\n");
        return;
    }

    char nomeRemover[MAX_NOME];
    printf("Nome do item que deseja remover: ");
    scanf(" %[^\n]", nomeRemover);

    No *atual = *inicio;
    No *anterior = NULL;
    bool encontrado = false;

    while (atual) {
        if (strcmp(atual->dados.nome, nomeRemover) == 0) {
            if (!anterior) *inicio = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            encontrado = true;
            printf("\n%s removido com sucesso!\n", nomeRemover);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (!encontrado)
        printf("\nItem não encontrado.\n");
}

void buscaSequencialLista(No *inicio) {
    if (!inicio) {
        printf("\nMochila vazia.\n");
        return;
    }

    char nomeBusca[MAX_NOME];
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int comparacoes = 0;
    bool encontrado = false;
    No *aux = inicio;

    while (aux) {
        comparacoes++;
        if (strcmp(aux->dados.nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("--------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
            printf("--------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10d\n", aux->dados.nome, aux->dados.tipo, aux->dados.quantidade);
            printf("--------------------------------------------------------------\n");
            encontrado = true;
            break;
        }
        aux = aux->proximo;
    }

    printf("Comparações realizadas: %d\n", comparacoes);
    if (!encontrado) printf("\nItem não encontrado.\n");
}

void executarMochilaLista() {
    No *inicio = NULL;
    int opcao;

    do {
        printf("\n--- MENU DE AÇÕES (LISTA ENCADEADA) ---\n");
        printf("1. Adicionar Item (Loot)\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens da Mochila\n");
        printf("4. Buscar Item por Nome\n");
        printf("0. Voltar ao menu principal\n");
        printf("-----------------------------------------\n");

        opcao = lerInt("Escolha uma opção: ");

        switch (opcao) {
            case 1: adicionarItemLista(&inicio); break;
            case 2: removerItemLista(&inicio); break;
            case 3: listarItensLista(inicio); break;
            case 4: buscaSequencialLista(inicio); break;
            case 0: printf("\nVoltando ao menu principal...\n"); break;
            default: printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    // Libera memória
    No *aux;
    while (inicio) {
        aux = inicio;
        inicio = inicio->proximo;
        free(aux);
    }
}
