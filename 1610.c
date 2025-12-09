/* Kauan Dias Caisley AED 1 Dudu Faz Serviço */

#include <stdio.h>
#include <stdlib.h>

#define NAO_VISITADO 0
#define VISITADANDO 1
#define VISITADO 2

int *adj[10005]; // lista de adjacência
int size[10005]; // quantidade de vizinhos
int cap[10005]; //capacidade alocada para cada lista
int state[10005]; // 0 = não visitado, 1 = visitando, 2 = finalizado
int hasCycle; //flag que detecta ciclo

void dfs(int u) {
    if (hasCycle) return;

    state[u] = VISITADANDO;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (state[v] == VISITADANDO) { 
            hasCycle = 1; 
            return;
        } else if (state[v] == NAO_VISITADO) {
            dfs(v);
        }
    }

    state[u] = VISITADO;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        //limpar estruturas
        for (int i = 1; i <= N; i++) {
            size[i] = 0;
            state[i] = NAO_VISITADO;
            cap[i] = 0;

            if (adj[i] != NULL) {
                free(adj[i]);
                adj[i] = NULL;
            }
        }

        //ler dependências
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);

            if (size[A] == cap[A]) {
                cap[A] = cap[A] == 0 ? 2 : cap[A] * 2;
                adj[A] = realloc(adj[A], cap[A] * sizeof(int));
            }

            adj[A][size[A]++] = B;
        }

        hasCycle = 0;

        // dfs
        for (int i = 1; i <= N && !hasCycle; i++) {
            if (state[i] == NAO_VISITADO) {
                dfs(i);
            }
        }

        if (hasCycle)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
