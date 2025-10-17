#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mochila_vetor.h"
#include "mochila_lista.h"

// ===============================================
// FREE FIRE - NÍVEL AVENTUREIRO
// Sistema de inventário (mochila de loot inicial)
// ===============================================

// -----------------------------------------------------
// Função principal
// -----------------------------------------------------
int main() {

    int opcao;

    printf("\n===============================================\n");
    printf("   MOCHILA DE SOBREVIVÊNCIA - CÓDIGO DA ILHA   \n");
    printf("===============================================\n");

    do {
        // Menu de opções
        printf("\n----- MENU PRINCIPAL -----\n");
        printf("1. Vetor\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair\n");
        printf("Escolha a estrutura de dados: ");
        scanf("%d", &opcao);
        printf("-----------------------------\n");

        switch (opcao) {
            case 1:
                executarMochilaVetor(); // função definida em mochila_vetor.c
                break;
            case 2:
                executarMochilaLista(); // função definida em mochila_lista.c
                break;
            case 0:
                printf("\nSaindo do jogo...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}