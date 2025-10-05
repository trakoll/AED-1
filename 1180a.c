/* Kauan Dias Caisley AED 1 Menor e Posição sem alocação dinamica*/

#include <stdio.h>

int main (){
    int n, menor, posicao, vetor[1000]; // definindo variaveis e vetor de tamanho máximo = 1000

    scanf("%d", &n);

    if (n < 1 || n > 1000) return 1; // tamanhos inválidos do vetor

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

    return 0;
}