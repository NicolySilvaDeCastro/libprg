//
// Created by aluno on 14/05/2026.
//
#include <stdlib.h>
#include <string.h>

#include "libprg/libprg.h"

typedef struct noh {
    char* chave;
    int valor;
    noh_t* proximo;
}noh_t;


typedef struct dicionario {
    int tamanho;
    noh_t** vetor;
}dicionario_t;


dicionario_t* criar_dicionario(int m){
    dicionario_t* d;
    if (m < 1) return NULL; //impede que o valor seja menor que 1
    d = malloc(sizeof(dicionario_t));
    d->vetor = malloc(m * sizeof (noh_t*));
    d->tamanho = m;

    return d;
}

int hash(char* chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];//casting, transforma o caractere da string em seu valor ascii para multiplicar pelo int
    }
    return soma % m;
}

int inserir_hash(dicionario_t* d, char* chave, int valor) {
    int indice = hash(chave, d->tamanho);
    noh_t* no = malloc(sizeof(noh_t));
    if (no == NULL) return 1; //sempre testar erro de malloc

    no->chave = strdup(chave);//faz uma cópia da chave para que o ponteiro não seja apagado pelo user
    if (no->chave == NULL) {
        free(no);
        return 1;
    }

    no->valor = valor;
    //TODO trartar colisões(encadeada):
    //...
    no->proximo = NULL;//indica fim da lista

    d->vetor[indice] = no;
    return 0;
}
