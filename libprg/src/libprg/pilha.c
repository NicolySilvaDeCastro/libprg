//
// Created by aluno on 17/03/2026.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int *elementos;
  int topo;
  int capacidade;
} pilha_t; // _t é uma convenção do C

pilha_t *criar_pilha(int capacidade) {
  pilha_t *pilha = malloc(sizeof(pilha_t));
  pilha->elementos = malloc(sizeof(int) * capacidade);
  pilha->topo = -1;
  pilha->capacidade = capacidade;

  return pilha;
}

int empilhar(pilha_t *pilha, int valor) {
  if (pilha->topo + 1 >= pilha->capacidade) {
    //aumentar capacidade
    pilha->capacidade *= 2;
    pilha->elementos = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
  }

  pilha->topo++;
  pilha->elementos[pilha->topo] = valor; //Elem[topo] = valor;

  return 0;
}


int desempilhar(pilha_t *pilha) {
  if (pilha->topo < 0) {
    exit(EXIT_FAILURE);
  }

  int valor = pilha->elementos[pilha->topo];
  pilha->topo--;

  /*
   *Minha tentativa
  pilha->elementos[pilha->topo] = valor;
  pilha->topo--;
  printf("Valor: %d\n", valor);
  */
  return valor;
}


int tamanho(pilha_t *pilha) {
  return pilha->topo + 1;
}


int vazia_pilha(pilha_t *pilha) {
  return pilha->topo < 0;

  /*if (pilha->topo < 0) {return 1;}
  return 0;*/
}

int destruir_pilha(pilha_t *pilha) {
  free(pilha->elementos); //liberar primeiro o que está encapsulado para não dar erro
  free(pilha);
  return 0;
}
