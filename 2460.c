/* Kauan Dias Caisley AED 1 Fila*/

#include <stdio.h>
#include <stdlib.h>



int main (){
    int N, M, *fila, *saiu;

    scanf ("%d", &N); // número de pessoas na fila

    fila = (int*) malloc (N * sizeof(int)); // fila inicial

    for (int i = 0; i < N; i++){
        scanf ("%d", &fila[i]); // indentificador da pessoa
    }

    scanf ("%d", &M); // número de pessoas que saíram da fila
    saiu = (int*) malloc (M * sizeof(int));

    for (int i = 0; i < M; i++){
        scanf ("%d", &saiu[i]); // indentificador da pessoa que saiu
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (saiu[i] == fila[j]){
                fila[j] = -1; // marca a pessoa que saiu
                break;
            }
        }
    }

    int primeiro;

    for (int i = 0; i < N; i++){
        if (fila[i] != -1){
            primeiro = i;
            break;
        }
    } // acho que eu tenho que fazer isso?

    for (int i = 0; i < N; i++){
        if (fila[i] != -1){
            if (i != primeiro){
                printf (" ");
            }
            printf ("%d", fila[i]); // imprime as pessoas que ficaram na fila
        }
    }
    printf ("\n"); // cara. POR QUE O EXERCÍCIO NÃO FALA ISSO????????????????????????????????? 

    return 0;
}