//
// Created by aluno on 28/04/2026.
//
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct no {
    int dado;
    no_t* proximo;
}no_t;

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
void inserir_encadeada(no_t** inicio, int dado) {
    nod_t* novo = criar_encadeada_dupla(dado);
    novo->proximo = *inicio;
    (*inicio)->anterior = novo;
    *inicio = novo;
}

//---------------------------------------
// CRIAR LISTA SEM RECEBER DADO INICIAL
// no_t* criar_lista_encadeada() {
//     no_t* no = malloc(sizeof(no_t));
//     no->dado = (int) NULL;
//     no->proximo = NULL;
//
//     return no;
// }

// CRIAR LISTA RECEBENDO DADO INICIAL
no_t* criar_lista_encadeada(int dado) {
    no_t* no = malloc(sizeof(no_t));
    no->dado = dado;
    no->proximo = NULL;

    return no;
}

void inserir_encadeada(no_t** inicio, int dado) {
    no_t* novo = criar_lista_encadeada(dado);
    //novo->dado = dado; //sem o dado inicial
    novo->proximo = *inicio;
    *inicio = novo;
}

no_t* buscar_lista_encadeada(no_t** inicio, int dado) {
    no_t* atual = *inicio;

    while (atual) {
        // igual á : while(atual =! NULL), porque quando o atual igual a nulo, então o atual é falso(não existe)
        if (atual->dado == dado) return atual;
        atual = atual->proximo;// não precisa do else, pois se o programa não executar o return, vai para a próxima
    }
    return NULL;
}

bool remover_lista_encadeada(no_t** inicio, int dado) {

    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual) {
        if (atual->dado == dado) {
            if (anterior == NULL) *inicio = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            return true;
        }

        anterior = atual;
        atual = atual->proximo;

    }
    return false;
}
void destruir_encadeada(no_t* inicio) {
    no_t* atual = inicio;

    while (atual) { //enquanto atual existe:
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}


//alterar_lista_encadeada
//ordenar_lista_encadeada
//combinar_lista_encadeada

