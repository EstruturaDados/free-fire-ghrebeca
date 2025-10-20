#include <stdio.h>
#include "utils.h"

int lerInt(const char *mensagem) {
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1) {
            while (getchar() != '\n'); // limpa buffer
            return valor;
        }
        printf("Entrada inválida! Tente novamente.\n");
        while (getchar() != '\n'); // limpa buffer
    }
}
