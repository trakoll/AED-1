/* Kauan Dias Caisley AED 1 Altura com Selection sort*/

#include <stdio.h>
#include <stdlib.h>

int* selection_sort (int *vetor, int N){
    int min, x, i, j;

    for (int i = 0; i < N-1 ; i++){ // para cada elemento do vetor
        min = i; // assumindo que o menor elemento e o primeiro
        
        for (j = i + 1; j < N ; j++ ){ // procurando o menor elemento no vetor
            if (vetor[j] < vetor[min]){
                min = j; // atualizando a posicao do menor elemento
            }
        }
        x = vetor[i]; // trocando o menor elemento com o primeiro
        vetor[i] = vetor[min];
        vetor[min] = x;
        
    }

    return vetor;
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

        vetor = selection_sort (vetor, N); // ordenando o vetor

        for (int j = 0; j < N; j++){
            printf("%d ", vetor[j]); // imprimindo o vetor ordenado
        }

        printf("\n");
        free(vetor); // liberando a memoria alocada
    }

    return 0;
}