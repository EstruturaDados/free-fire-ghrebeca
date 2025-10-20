#include <stdio.h>
#include "mochila_vetor.h"
#include "mochila_lista.h"
#include "utils.h" // inclui a funcao lerInt

int main() {
    int opcao;
    do {
        printf("\n===============================================\n");
        printf("   MOCHILA DE SOBREVIVÊNCIA - CÓDIGO DA ILHA   \n");
        printf("===============================================\n");
        printf("\n----- MENU PRINCIPAL -----\n");
        printf("1. Vetor\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair\n");

        opcao = lerInt("Escolha a estrutura de dados: ");

        switch (opcao) {
            case 1: executarMochilaVetor(); break;
            case 2: executarMochilaLista(); break;
            case 0: printf("\nSaindo do jogo...\n"); break;
            default: printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
