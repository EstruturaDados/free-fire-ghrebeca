#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITENS 20  // Número máximo de componentes

// ======================== ESTRUTURA ========================
// Define cada componente da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade;
} Componente;

// ======================== VARIÁVEIS GLOBAIS ========================
Componente mochila[MAX_ITENS];
int totalItens = 0;
char statusOrdenacao[20] = "NÃO ORDENADO";  // Status da ordenação por nome

// ======================== FUNÇÕES ========================

// Lista todos os componentes da mochila
void listarComponentes() {
    if (totalItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA ---\n");
    printf("---------------------------------------------------------------------------\n");
    printf("%-25s | %-20s | %-10s | %-10s\n", "NOME", "TIPO", "QUANTIDADE", "PRIORIDADE");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < totalItens; i++) {
        printf("%-25s | %-20s | %-10d | %-10d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
    printf("---------------------------------------------------------------------------\n");
}

// Adiciona um novo componente à mochila
void adicionarComponente() {
    if (totalItens >= MAX_ITENS) {
        printf("\nMochila cheia!\n");
        return;
    }

    Componente novo;
    printf("\n--- Coletando Novo Componente ---\n");

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0; // remove \n

    printf("Tipo (Controle, Suporte, Propulsão): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = 0; // remove \n

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar(); // limpa \n do buffer

    printf("Prioridade de Montagem (1-10): ");
    scanf("%d", &novo.prioridade);
    getchar(); // limpa \n do buffer

    mochila[totalItens++] = novo;
    printf("\nComponente '%s' adicionado com sucesso!\n", novo.nome);
}

// Descarta um componente da mochila pelo nome
void descartarComponente() {
    if (totalItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    char nomeDescartar[30];
    bool descartado = false;

    printf("\n--- Descartando Componente ---\n");
    printf("Nome do Componente que deseja descartar: ");
    fgets(nomeDescartar, sizeof(nomeDescartar), stdin);
    nomeDescartar[strcspn(nomeDescartar, "\n")] = 0; // remove \n

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeDescartar) == 0) {
            for (int j = i; j < totalItens - 1; j++)
                mochila[j] = mochila[j + 1];
            totalItens--;
            descartado = true;
            printf("\nComponente '%s' descartado com sucesso!\n", nomeDescartar);
            break;
        }
    }

    if (!descartado)
        printf("\nComponente '%s' não encontrado!\n", nomeDescartar);
}

// ======================== FUNÇÕES DE ORDENAÇÃO ========================

// Bubble Sort - Ordena por nome (alfabético)
void ordenarPorNome() {
    int comparacoes = 0;
    clock_t inicio = clock();

    for (int i = 0; i < totalItens - 1; i++) {
        for (int j = 0; j < totalItens - i - 1; j++) {
            comparacoes++;
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                Componente temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    strcpy(statusOrdenacao, "ORDENADO");
    printf("\nMochila ordenada por nome!\nComparações: %d | Tempo: %.6f s\n", comparacoes, tempo);
}

// Insertion Sort - Ordena por tipo
void ordenarPorTipo() {
    int comparacoes = 0;
    clock_t inicio = clock();

    for (int i = 1; i < totalItens; i++) {
        Componente key = mochila[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (strcmp(mochila[j].tipo, key.tipo) > 0) {
                mochila[j + 1] = mochila[j];
                j--;
            } else break;
        }
        mochila[j + 1] = key;
    }

    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nMochila ordenada por tipo!\nComparações: %d | Tempo: %.6f s\n", comparacoes, tempo);
}

// Selection Sort - Ordena por prioridade
void ordenarPorPrioridade() {
    int comparacoes = 0;
    clock_t inicio = clock();

    for (int i = 0; i < totalItens - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < totalItens; j++) {
            comparacoes++;
            if (mochila[j].prioridade < mochila[min_idx].prioridade)
                min_idx = j;
        }
        if (min_idx != i) {
            Componente temp = mochila[i];
            mochila[i] = mochila[min_idx];
            mochila[min_idx] = temp;
        }
    }

    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nMochila ordenada por prioridade!\nComparações: %d | Tempo: %.6f s\n", comparacoes, tempo);
}

// Menu de escolha de ordenação
void ordenarComponentes() {
    int opcao;
    do {
        printf("\n--- Estratégia de Organização ---\n");
        printf("1. Por Nome (Ordem Alfabética)\n");
        printf("2. Por Tipo\n");
        printf("3. Por Prioridade\n");
        printf("0. Cancelar\nEscolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        switch (opcao) {
            case 1: ordenarPorNome(); break;
            case 2: ordenarPorTipo(); break;
            case 3: ordenarPorPrioridade(); break;
            case 0: printf("Voltando ao menu...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

// Busca binária por nome
void buscaBinaria() {
    if (strcmp(statusOrdenacao, "ORDENADO") != 0) {
        printf("\nA busca binária requer que a mochila esteja ordenada por NOME!\n");
        return;
    }

    if (totalItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\n--- Busca Binária ---\nNome do componente: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0; // remove \n

    int inicio = 0, fim = totalItens - 1, comparacoes = 0;
    bool encontrado = false;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;
        int cmp = strcmp(mochila[meio].nome, nomeBusca);

        if (cmp == 0) {
            printf("\nComponente encontrado!\n");
            printf("---------------------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10s | %-10s\n", "NOME", "TIPO", "QUANTIDADE", "PRIORIDADE");
            printf("---------------------------------------------------------------------------\n");
            printf("%-25s | %-20s | %-10d | %-10d\n",
                   mochila[meio].nome, mochila[meio].tipo, mochila[meio].quantidade, mochila[meio].prioridade);
            printf("---------------------------------------------------------------------------\n");
            encontrado = true;
            break;
        } else if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }

    if (!encontrado)
        printf("\nItem não encontrado.\n");

    printf("Comparações realizadas: %d\n", comparacoes);
}

// ======================== MAIN ========================
int main() {
    int opcao;

    printf("\n=====================================================\n");
    printf("   PLANO DE FUGA - CÓDIGO DA ILHA (NÍVEL MESTRE)   \n");
    printf("=====================================================\n");

    do {
        printf("\nItens na Mochila: %d/20 | Status Ordenação por Nome: %s\n", totalItens, statusOrdenacao);
        printf("\n========= MENU DE AÇÕES =========\n");
        printf("1. Adicionar Componente\n2. Descartar Componente\n3. Listar Componentes\n");
        printf("4. Organizar Mochila\n5. Busca Binária por Componente\n0. Ativar Torre de Fuga (Sair)\n");
        printf("=================================\nEscolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        switch (opcao) {
            case 1: adicionarComponente(); listarComponentes(); break;
            case 2: descartarComponente(); listarComponentes(); break;
            case 3: listarComponentes(); break;
            case 4: ordenarComponentes(); listarComponentes(); break;
            case 5: buscaBinaria(); break;
            case 0: printf("\nSaindo do jogo...\n"); break;
            default: printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
