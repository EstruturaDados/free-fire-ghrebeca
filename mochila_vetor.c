#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "mochila_vetor.h"
#include "utils.h" // inclui a funcao lerInt

Item mochila[MAX_ITENS];
int totalItens = 0;

void listarItensVetor() {
    if (totalItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }
    printf("\n--- ITENS NA MOCHILA ---\n");
    printf("--------------------------------------------------------------\n");
    printf("%-25s | %-20s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%-25s | %-20s | %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("--------------------------------------------------------------\n");
}

void adicionarItemVetor() {
    if (totalItens >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }

    Item novo;
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Tipo do item: ");
    scanf(" %[^\n]", novo.tipo);
    novo.quantidade = lerInt("Quantidade: ");

    mochila[totalItens++] = novo;
    printf("\nItem adicionado com sucesso!\n");
}

void buscarItemVetor() {
    if (totalItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    char nomeBusca[MAX_NOME];
    printf("Digite o nome do item a buscar: ");
    scanf(" %[^\n]", nomeBusca);

    bool encontrado = false;
    int comparacoes = 0;
    for (int i = 0; i < totalItens; i++) {
        comparacoes++;
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("--------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
            printf("--------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            printf("--------------------------------------------------------------\n");
            encontrado = true;
            break;
        }
    }

    printf("Comparações realizadas: %d\n", comparacoes);
    if (!encontrado) printf("\nItem não encontrado.\n");
}

void executarMochilaVetor() {
    int opcao;
    do {
        printf("\n--- MENU DE AÇÕES (VETOR) ---\n");
        printf("1. Adicionar Item (Loot)\n");
        printf("2. Listar Itens da Mochila\n");
        printf("3. Buscar Item por Nome\n");
        printf("0. Voltar ao menu principal\n");
        printf("-----------------------------------------\n");
        opcao = lerInt("Escolha uma opção: ");

        switch (opcao) {
            case 1: adicionarItemVetor(); break;
            case 2: listarItensVetor(); break;
            case 3: buscarItemVetor(); break;
            case 0: printf("\nVoltando ao menu principal...\n"); break;
            default: printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
}
