/* BEE1180.c | Menor e Posição | AED 1 | Kauan Dias Caisley*/

#include <stdio.h>
#include <stdlib.h>

int main (){
    int n, *x, posicao;

    scanf ("%d", &n);
    x = (int*) malloc (n * sizeof(int)); // alocando memoria para n inteiros

    for (int i=0; i<n; i++){

        scanf ("%d", &x[i]);
        getchar (); // lendo o espaco ou a quebra de linha

        if (i==0){ // se é a primeira iteração, necessáriamente é o menor
            posicao = i;
        }
        if (x[i]<x[posicao]){ // se o valor atual é menor que o menor, atualiza
            posicao = i;
        }
    }

    printf ("Menor valor: %d\n", x[posicao]);
    printf ("Posicao: %d\n", posicao);

    free (x); // liberando a memoria alocada para o vetor
    
    return 0;
}