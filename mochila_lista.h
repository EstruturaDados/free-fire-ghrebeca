#ifndef MOCHILA_LISTA_H
#define MOCHILA_LISTA_H

#include "item.h" // Inclui a struct Item
#include <stdbool.h>

// Estrutura do nó
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// Protótipos das funções
void executarMochilaLista();
void listarItensLista(No *inicio);
void adicionarItemLista(No **inicio);
void removerItemLista(No **inicio);
void buscaSequencialLista(No *inicio);

#endif
