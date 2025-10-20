#ifndef ITEM_H
#define ITEM_H

#define MAX_NOME 50
#define MAX_TIPO 20

typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
} Item;

#endif
