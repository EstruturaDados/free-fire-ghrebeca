#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// ===============================================
// FREE FIRE - NÍVEL NOVATO
// Sistema de inventário (mochila de loot inicial)
// ===============================================

// Estrutura que representa um item da mochila
typedef struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// -----------------------------------------------------
// Função que lista os itens da mochila
// -----------------------------------------------------
void listarItens(Item mochila[], int qtdItens) {
    printf("\n--- ITENS NA MOCHILA (%d/10) ---\n", qtdItens);
    printf("--------------------------------------------------------------\n");
    printf("%-25s | %-20s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < qtdItens; i++) {
        printf("%-25s | %-20s | %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }

    if (qtdItens == 0) {
        printf("Mochila vazia.\n");
    }

    printf("--------------------------------------------------------------\n");
}

// -----------------------------------------------------
// Função que adiciona um item na mochila
// -----------------------------------------------------
void adicionarItem(Item mochila[], int *qtdItens) {
    if (*qtdItens >= 10) {
        printf("\nA mochila está cheia! Remova algo antes de adicionar.\n");
        return;
    }

    Item novo;
    printf("\n--- Cadastro de Item %d ---\n", *qtdItens + 1);
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Tipo do item (ex: arma, munição, cura): ");
    scanf(" %[^\n]", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*qtdItens] = novo;
    (*qtdItens)++;

    printf("\nItem adicionado com sucesso!\n");
}

// -----------------------------------------------------
// Função que remove um item da mochila
// -----------------------------------------------------
void removerItem(Item mochila[], int *qtdItens) {
    if (*qtdItens <= 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char itemRemover[30];
    printf("\nNome do item que deseja remover: ");
    scanf(" %[^\n]", itemRemover);

    bool encontrado = false;

    for (int i = 0; i < *qtdItens; i++) {
        if (strcmp(mochila[i].nome, itemRemover) == 0) {
            // Desloca os itens para preencher o espaço do removido
            for (int j = i; j < *qtdItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*qtdItens)--;
            encontrado = true;
            printf("\n%s removido com sucesso!\n", itemRemover);
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem não encontrado na mochila.\n");
    }
}

// -----------------------------------------------------
// Função que busca um item pelo nome
// -----------------------------------------------------
void buscarItem(Item mochila[], int qtdItens) {
    if (qtdItens == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    bool encontrado = false;

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("--------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
            printf("--------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10d\n",
                   mochila[i].nome,
                   mochila[i].tipo,
                   mochila[i].quantidade);
            printf("--------------------------------------------------------------\n");
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem não encontrado.\n");
    }
}

// -----------------------------------------------------
// Função principal
// -----------------------------------------------------
int main() {
    Item mochila[10];     // vetor para armazenar até 10 itens
    int qtdItens = 0;     // quantidade atual de itens
    int opcao;

    printf("\n===============================================\n");
    printf("   MOCHILA DE SOBREVIVÊNCIA - CÓDIGO DA ILHA   \n");
    printf("===============================================\n");

    do {
        // Menu de opções
        printf("\n--- MENU DE AÇÕES ---\n");
        printf("1. Adicionar Item (Loot)\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens da Mochila\n");
        printf("4. Buscar Item\n");
        printf("0. Sair\n");
        printf("-----------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem(mochila, &qtdItens);
                listarItens(mochila, qtdItens);
                break;
            case 2:
                removerItem(mochila, &qtdItens);
                listarItens(mochila, qtdItens);
                break;
            case 3:
                listarItens(mochila, qtdItens);
                break;
            case 4:
                buscarItem(mochila, qtdItens);
                break;
            case 0:
                printf("\nSaindo do jogo...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    printf("\nJogo encerrado.\n");
    return 0;
}
