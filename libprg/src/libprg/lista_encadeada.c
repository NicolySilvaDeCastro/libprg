//
// Created by aluno on 28/04/2026.
//
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int dado;
    no_t* proximo;
}no_t;

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


//buscar_lista_encadeada
//remover_lista_encadeada
//alterar_lista_encadeada
//ordenar_lista_encadeada
//combinar_lista_encadeada
//destruit_lista_encadeada

