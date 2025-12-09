/* Kauan Dias Caisley AED 1 Tabela Hash*/

#include <stdio.h>

int main() {
    int N;  // quantidade de casos de teste
    scanf("%d", &N);

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        int hash[M][C];     // matriz para guardar encadeamento
        int tam[M];         // tamanho de cada lista
        for (int i = 0; i < M; i++) tam[i] = 0;

        // lê chaves e insere
        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);
            int h = x % M;
            hash[h][tam[h]++] = x;
        }

        // imprime tabela
        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < tam[i]; j++) {
                printf(" %d ->", hash[i][j]);
            }
            printf(" \\\n"); // "\" e pula linha
        }

        if (N) printf("\n");  // linha em branco entre casos
    }

    return 0;
}
