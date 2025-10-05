/* Kauan Dias Caisley AED 1 Menor e Posição com alocação dinamica*/

#include <stdio.h>
#include <stdlib.h>

int main (){
    int n, menor, posicao, *vetor; // definindo variaveis e ponteiro para o vetor

    scanf("%d", &n);

    if (n < 1 || n > 1000) return 1; // tamanhos inválidos do vetor

    vetor = (int*) malloc (n * sizeof(int)); // alocando dinamicamente o vetor

    // o resto é igual ao 1180a.c tirando o free no final

    for (int i = 0; i < n; i++){ // lendo os valores do vetor
        scanf("%d", &vetor[i]);

        if (i == 0){ // o primerio valor lido é o menor até o momento
            menor = vetor[i];
            posicao = i;
        }

        else if (vetor[i] < menor){ // se o valor lido for menor que o menor até o momento, atualiza o menor e a posição
            menor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free (vetor); // liberando a memória alocada

    return 0;
}
