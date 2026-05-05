//
// Created by aluno on 05/05/2026.
//

#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

//Lista encadeada dupla:
typedef struct nod {
    int dado;
    nod_t* proximo;
    nod_t* anterior;
}nod_t;

nod_t* criar_encadeada_dupla(int dado) {
    nod_t* no = malloc(sizeof(nod_t));
    no->dado = dado;
    no->anterior = NULL;
    no->proximo = NULL;

    return no;
}
void inserir_encadeada_dupla(no_t** inicio, int dado) {
    nod_t* novo = criar_encadeada_dupla(dado);
    novo->proximo = *inicio;
    (*inicio)->anterior = novo;
    *inicio = novo;
}

no_t* buscar_lista_encadeada_dupla(nod_t** inicio, int dado) {
    nod_t* atual = *inicio;

    while (atual) {
        if (atual->dado == dado) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

bool remover_lista_encadeada_dupla(no_t** inicio, int dado) {

    no_t* atual = *inicio;

    while (atual) {
        if (atual->dado == dado) {
            if (anterior == NULL) *inicio = atual->proximo;
            else {
                atual->anterior->proximo = atual->proximo;
                atual->anterior->proximo = atual->anterior;

            }

            free(atual);
            return true;
        }

        atual = atual->proximo;

    }
    return false;
}

void destruir_encadeada_dupla(nod_t* inicio) {
    nod_t* atual = inicio;

    while (atual) { //enquanto atual existe:
        nod_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}