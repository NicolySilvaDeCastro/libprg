//
// Created by aluno on 12/05/2026.
//

//BUBLE SORT:
// int* bubble_sort(int* vetor, int tamanho) {
//     for (int i = 0; i < tamanho - 1; i++) {
//         for (int j = i + 1; j < tamanho; j++) {
//             if (vetor[j] > vetor[j+1]) {
//                 int aux = vetor[j];
//                 vetor[j] = vetor[j+1];
//                 vetor[j+1] = aux;
//
//                 return vetor;
//             }
//         }
//     }
// }

//MERGE SORT
int* merge(int* vetor, int esquerda, int meio, int direita) { //a função merge não vai para o header, pois não funciona sozinho sem o merge_sort
    int aux[direita - esquerda+1];
    int i = esquerda, j = meio, k = 0;

    while (i <= meio && j <= direita) {
        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i];
            i++;
        }else {
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }

    //linha além da 13
    while (i <= meio) {
        aux[k] = vetor[i];
        i++, k++;
    }
    while (j <= direita) {
        aux[k] = vetor[j];
        j++, k++;
    }
    for (int i = esquerda; i <= direita; i++ ) {
        vetor[i] = aux[i - esquerda];
    }
}


int* merge_sort(int* vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (esquerda - direita) /2;
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
    return vetor;
}

