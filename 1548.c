/* Kauan Dias Caisley AED 1 Fila do Recreio*/

#include <stdio.h>
#include <stdlib.h>

void sortmaiormenor (int *fila, int M){
    int aux, i, j;

    for (i = 0; i < M-1; i++){
        for (j = 0; j < M-i-1; j++){
            if (fila[j] < fila[j+1]){
                aux = fila[j];
                fila[j] = fila[j+1];
                fila[j+1] = aux;
            }
        }
    }
}

int contacerto (int *fila, int *filacerta, int M){
    int count = 0;

    for (int i = 0; i < M; i++){
        if (fila[i] == filacerta[i]){
            count++;
        }
    }

    return count;
}

int main (){
    int N, M, *fila, *filacerta;

    scanf ("%d", &N); // número de casos

    for (int i = 0; i < N; i++){
        scanf ("%d", &M); // número de alunos
        fila = (int*) malloc (M * sizeof(int));

        for (int j = 0; j < M; j++){
            scanf ("%d", &fila[j]); // nota do aluno na fila
        }

        filacerta = malloc (M * sizeof(int));
        for (int j = 0; j < M; j++){
            filacerta[j] = fila[j];
        }

        sortmaiormenor (filacerta, M); // ordena a fila correta
        printf ("%d\n", contacerto (fila, filacerta, M)); // conta quantos alunos estão na posição correta
        
        free (fila);
        free (filacerta);
    }

    return 0;
}