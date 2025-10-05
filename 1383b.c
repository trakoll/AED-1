/* Kauan Dias Caisley AED 1 Sudoku com alocação dinamica*/

#include <stdio.h>
#include <stdlib.h>

/* definindo o tipo sudoku */
typedef struct sudoku {
    int grid[9][9]; // grid 9x9
} sudoku;

int teste (sudoku s){
    int l[9], c[9], b[9];// para verificar linhas e colunas

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            l[j] = 0; // zerando o vetor de linhas
            c[j] = 0; // zerando o vetor de colunas
            b[j] = 0; // zerando o vetor de blocos
        }
        
        // verificando linha 
        for (int j = 0; j < 9; j++) {
            if (l[s.grid[i][j]-1] == 1) return 0; // numero repetido na linha
            l[s.grid[i][j]-1] = 1; // marcando o numero como visto
        }
        // verificando coluna
        for (int j = 0; j < 9; j++) {
            if (c[s.grid[j][i]-1] == 1) return 0; // numero repetido na coluna
            c[s.grid[j][i]-1] = 1; // marcando o numero como visto
        }
        // verificando bloco a lógica tem uma matemática meio chata https://imgur.com/a/6vc1RoL
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (b[s.grid[(i%3)*3 + j][(i%3)*3+k]-1] == 1) return 0; // numero repetido no bloco
                b[s.grid[((i%3*3))+j][(i%3)*3+k]-1] = 1; // marcando o numero como visto
            }
        }

    }

    return 1; // sudoku valido
}

int main (){
    int n;
    sudoku* sudokus; // array de sudokus

    scanf("%d", &n);
    sudokus = (sudoku*) malloc(n * sizeof(sudoku)); // alocando memoria para n sudokus

    for (int k = 0; k < n; k++) {
        // lendo cada sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudokus[k].grid[i][j]);
                getchar (); // lendo o espaco ou a quebra de linha >:(
            }
        }
    }

    /* debug
    printf ("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                printf ("%d ", sudokus[i].grid[j][k]);
            }
            printf ("\n");
        }
        printf ("\n");
    } // printando os sudokus lidos */

    for (int k = 0; k < n; k++) {
        if (teste(sudokus[k]) == 1) printf ("Instancia %d\nSIM\n\n", k+1);
        else printf ("Instancia %d\nNAO\n\n", k+1);
    }

    free (sudokus); // liberando memoria
    return 0;

}
