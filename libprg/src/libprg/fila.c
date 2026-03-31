//
// Created by aluno on 26/03/2026.
//

#include <stdlib.h>

typedef struct fila {
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;

}fila_t;


fila_t* criar_fila(int capacidade) {

    fila_t* fila = malloc(sizeof(fila_t)); //aloca capacidade
    fila->elementos = malloc(sizeof(int) * capacidade); //
    fila-> inicio = 0;
    fila->fim = 0;
    fila->capacidade = capacidade;
    return fila;
}

void enfileirar(fila_t* fila, int valor) {

    if (fila->tamanho >= fila->capacidade) exit(EXIT_FAILURE);

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila-> capacidade;
    fila->tamanho++;

}
int desenfileirar(fila_t* fila) {

    if (fila->tamanho>0) {
        fila->fim = fila->fim - 1;
    }
    return 0;
}


//retornar elemento no inicio
int inicio(fila_t* fila) {

    return fila->elementos[fila->inicio];

}


//retornar elemento no fim
int fim(fila_t* fila) {

    return fila->elementos[fila->fim];
}


int vazia_pilha(fila_t* fila) {

    if (fila->tamanho==0) return 1;
    return 0;

}

int cheia(fila_t* fila) {
    if (fila->tamanho == fila->capacidade) return 1;
  return 0;
}


int destruir_fila(fila_t* fila) {
    free(fila->elementos);
    free(fila);
    return 0;
}
