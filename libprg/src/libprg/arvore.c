//
// Created by aluno on 19/05/2026.
//

#include <stdbool.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct noarv {
    int dado;
    noarv_t* esquerda;
    noarv_t* direita;

}noarv_t;



noarv_t* criar_noarv(int dado) {//Shift + F6 para renomear

    noarv_t* no = malloc(sizeof(noarv_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

noarv_t* adicionar_arvore(noarv_t* raiz, int dado) {

    if (raiz == NULL) return criar_noarv(dado);

    if (raiz->dado < dado) raiz->direita = adicionar_arvore(raiz->direita, dado);
    //se o dado novo for igual, ele caí no else e é adicionado na esquerda
    else raiz->esquerda = adicionar_arvore(raiz->esquerda, dado);

    return raiz;

}

bool remover_arvore(noarv_t** inicio, int dado) {

}
void destruir_arvore(noarv_t* inicio);

// adicionar
// remover
// destruir