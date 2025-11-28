/* Kauan Dias Caisley AED 1 Desenhando Labirintos */

#include <stdio.h>

void limpa_matriz(int m[50][50], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            m[i][j] = 0;
        }
    }
}

int conta_arestas(int m[50][50], int v) {
    int c = 0;

    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) { // se a aresta não é única
            if (m[i][j]) 
                c++;
        }
    }

    return c;
}

int main () {
    int T;
    scanf("%d", &T);

    while (T--) {

        int N, V, A;
        int u, v;
        int matriz[50][50];

        scanf("%d", &N);
        scanf("%d %d", &V, &A);

        limpa_matriz(matriz, V);

        for (int i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);

            if (u != v) {
                matriz[u][v] = 1;
                matriz[v][u] = 1;
            }
        }

        int unicas = conta_arestas(matriz, V);

        printf("%d\n", 2 * unicas); // não importa o caminho, sempre vai precisar percorrer no mínimo 2 vezes a mesma aresta (se tivesse só uma), como podem ter 2, é o 2 * o total de únicas
    }

    return 0;
}
