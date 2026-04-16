//
// Created by aluno on 16/04/2026.
//

#include <stdbool.h>
#include <stdlib.h>

#define CAPACIDADE_INICIAL 10 //OBS: constantes geralmente são escritas em capslock

typedef struct lista_linear {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t *criar_lista(bool ordenada) {
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;

    return lista;
}

//lista_linear_t *inserir(int *elementos) {
//}

lista_linear_t *buscar() {
    if (lista->ordenada) {
        //indice = buscar_binario;
    }else {
       //indice = buscar_linear;
    }

} //- 2 buscas - 1 ordenada(buscar_binario) - 1 não ordenada(buscar_linear)

lista_linear_t* remover(lista_linear_t *lista, int alvo) {
    int indice = buscar(lista, alvo);

    return lista;
}


//alterar
//ordenar
//combinar
//destruit