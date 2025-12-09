/* Kauan Dias Caisley AED 1 Itinerário do Papai Noel*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int w;
} Aresta;

int cmpAresta(const void *a, const void *b) {
    Aresta *ea = (Aresta*)a;
    Aresta *eb = (Aresta*)b;
    return ea->w - eb->w;
}

int *pai;
int *lvl;

int find_set(int x) {
    if (pai[x] != x) pai[x] = find_set(pai[x]);
    return pai[x];
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (lvl[a] < lvl[b]) {
        pai[a] = b;
    } else if (lvl[a] > lvl[b]) {
        pai[b] = a;
    } else {
        pai[b] = a;
        lvl[a]++;
    }
}

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N) == 2) {
        if (M == 0 && N == 0) break;

        Aresta *arestas = (Aresta*) malloc(sizeof(Aresta) * N);
        for (int i = 0; i < N; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            arestas[i].u = x;
            arestas[i].v = y;
            arestas[i].w = z;
        }

        qsort(arestas, N, sizeof(Aresta), cmpAresta);

        pai = (int*) malloc(sizeof(int) * M);
        lvl = (int*) malloc(sizeof(int) * M);
        for (int i = 0; i < M; i++) {
            pai[i] = i;
            lvl[i] = 0;
        }

        long long total = 0;
        int taken = 0;

        for (int i = 0; i < N && taken < M - 1; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            if (find_set(u) != find_set(v)) {
                union_set(u, v);
                total += arestas[i].w;
                taken++;
            }
        }

        printf("%lld\n", total);

        free(arestas);
        free(pai);
        free(lvl);
    }
    return 0;
}
