/* Kauan Dias Caisley AED 1 Sudoku sem alocação dinamica*/

#include <stdio.h>

int main (){
    int n, sudoku[9][9];

    scanf("%d", &n);

    for (int i = 0; i < n; i++){ // fazendo n casos de teste

        for (int j = 0; j < 9; j++){
            for (int k = 0; k < 9; k++){
                scanf("%d", &sudoku[j][k]); // lendo o sudoku
            }
        }

        int valido = 1; // assumindo que o sudoku é válido até provar o contrário

        // verificando linhas
        for (int j = 0; j < 9; j++){
            int numeros[10] = {0}; // vetor para marcar os números já vistos na linha

            for (int k = 0; k < 9; k++){
                int num = sudoku[j][k];

                if (numeros[num]){ // número fora do intervalo ou já visto
                    valido = 0;
                    break;
                }

                numeros[num] = 1; // marcando o número como visto
            }

            if (!valido) break; // se já foi encontrado um erro, sai do loop
        }

        // verificando colunas
        if (valido){
            for (int j = 0; j < 9; j++){
                // mesma lógica das linhas
                int numeros[10] = {0};

                for (int k = 0; k < 9; k++){
                    int num = sudoku[k][j];

                    if (numeros[num]){
                        valido = 0;
                        break;
                    }

                    numeros[num] = 1;
                }

                if (!valido) break;
            }
        }

        // verificando quadrados 3x3
        if (valido){
            for (int j = 0; j < 9; j = j + 3){
                for (int k = 0; k < 9; k = k + 3){
                    int numeros[10] = {0}; // mesma lógica do resto

                    for (int l = 0; l < 3; l++){
                        for (int m = 0; m < 3; m++){
                            int num = sudoku[j + l][k + m]; // pegando o número do quadrado

                            if (numeros[num]){ // número fora já visto
                                valido = 0;
                                break;
                            }

                            numeros[num] = 1;
                        }

                        // isso é meio feio mas é pra sair dos dois loops

                        if (!valido) break;
                    }

                    if (!valido) break;
                }

                if (!valido) break;
            }
        }

        if (valido) printf("Instancia %d\nSIM\n\n", i + 1);
        else printf("Instancia %d\nNAO\n\n", i + 1);

    }

}