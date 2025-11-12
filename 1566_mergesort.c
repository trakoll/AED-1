/* Kauan Dias Caisley AED 1 Altura com Merge sort*/

#include <stdio.h>
#include <stdlib.h>

void intercala (int *vetor, int inicio, int meio, int fim){
    int i, j, k; // indices para os vetores
    int *w = (int *) malloc((fim - inicio) * sizeof(int)); // vetor auxiliar
    
    i = inicio; j = meio; k = 0; // inicializando os indices

    while (i < meio && j < fim){ // enquanto nao chegar ao fim de um dos vetores
        if (vetor[i] <= vetor[j]){ // comparando os elementos
            w[k++] = vetor[i++]; // copiando o menor elemento para o vetor auxiliar
        } else {
            w[k++] = vetor[j++]; // copiando o menor elemento para o vetor auxiliar
        }
    }

    while (i < meio){ // copiando o resto do vetor esquerdo
        w[k++] = vetor[i++];
    }

    while (j < fim){ // copiando o resto do vetor direito
        w[k++] = vetor[j++];
    }

    for (i = inicio; i < fim; i++){ // copiando o vetor auxiliar de volta para o vetor original
        vetor[i] = w[i - inicio];
    }
 
    free(w); // liberando a memoria
}

void merge_sort (int *vetor, int inicio, int fim){
    if (fim - inicio > 1){
        int meio = (inicio + fim) / 2;
        merge_sort (vetor, inicio, meio);
        merge_sort (vetor, meio, fim);
        intercala (vetor, inicio, meio, fim);
    }
}


int main (){
    int NC, N, *vetor; // NC = numbero de cidades, N = numbero de habitantes

    scanf("%d", &NC); // lendo o numero de cidades
    getchar();

    for (int i = 0; i < NC; i++){ // para cada cidade
        scanf("%d", &N); // lendo o numero de habitantes
        getchar();

        vetor = (int *) malloc(N * sizeof(int)); // alocando memoria para o vetor

        for (int j = 0; j < N; j++){
            scanf("%d", &vetor[j]); // lendo a altura de cada habitante
            getchar();
        }

        merge_sort (vetor, 0, N); // ordenando o vetor

        int j = 0;
        for (j; j < N-1; j++){
            printf("%d ", vetor[j]); // imprimindo o vetor ordenado
        }
        printf("%d", vetor[j]); // imprimindo o ultimo elemento sem espaco no final porque a vida é muito triste e cruel

        printf("\n");
        free(vetor); // liberando a memoria alocada
    }

    return 0;
}