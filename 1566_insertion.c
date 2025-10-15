/* Kauan Dias Caisley AED 1 Altura com Selection sort*/

#include <stdio.h>
#include <stdlib.h>

int* inserction_sort (int *vetor, int N){
    int x, i, j;

    for (int i = 1; i < N; i++){ // para cada elemento do vetor
        x = vetor[i]; // pegando o elemento a ser inserido
        
        for (j = i - 1; j >= 0 && vetor[j] > x; j--){ // procurando a posicao correta para o elemento
            vetor[j + 1] = vetor[j]; // deslocando os elementos para a direita
        }
        vetor[j + 1] = x; // inserindo o elemento na posicao correta
        
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

        vetor = inserction_sort(vetor, N); // ordenando o vetor

        for (int j = 0; j < N; j++){
            printf("%d ", vetor[j]); // imprimindo o vetor ordenado
        }

        printf("\n");
        free(vetor); // liberando a memoria alocada
    }

    return 0;

}
