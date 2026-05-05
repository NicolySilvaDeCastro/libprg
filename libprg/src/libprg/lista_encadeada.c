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

typedef struct lista_encadeada {
    no_t* inicio;
    bool ordenada;
}lista_encadeada_t;


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
no_t* criar_no(int dado) {//Shift + F6 para renomear
    no_t* no = malloc(sizeof(no_t));
    no->dado = dado;
    no->proximo = NULL;

    return no;
}


lista_encadeada_t* criar_lista_encadeada_dupla(bool ordenada) {
    lista_encadeada_t* lista = malloc(sizeof(lista_encadeada_t));
    lista->inicio = NULL;
    lista->ordenada = ordenada;
    return lista;
}

void inserir_encadeada(lista_encadeada_t* lista, int dado) {
    no_t* novo = criar_no(dado);
    //novo->dado = dado; //sem o dado inicial
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

no_t* buscar_lista_encadeada(lista_encadeada_t* lista, int dado) {
    no_t* atual = lista->inicio;

    while (atual) {
        // igual á : while(atual =! NULL), porque quando o atual igual a nulo, então o atual é falso(não existe)
        if (atual->dado == dado) return atual;
        atual = atual->proximo;// não precisa do else, pois se o programa não executar o return, vai para a próxima
    }
    return NULL;
}

bool remover_lista_encadeada(lista_encadeada_t* lista, int dado) {

    no_t* atual = lista->inicio;
    no_t* anterior = NULL;

    while (atual) {
        if (atual->dado == dado) {
            if (anterior == NULL) lista->inicio = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            return true;
        }

        anterior = atual;
        atual = atual->proximo;

    }
    return false;
}
void destruir_encadeada(lista_encadeada_t* lista) {
    no_t* atual = lista->inicio;

    while (atual) { //enquanto atual existe:
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
}


//alterar_lista_encadeada
//ordenar_lista_encadeada
//combinar_lista_encadeada

