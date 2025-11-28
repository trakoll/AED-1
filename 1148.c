/* Kauan Caisley AED 1 Países em Guerra*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 1000000000
#define MAXN 500
#define MAXE 250000

typedef struct {
    int to, w, next;
} Edge;

Edge edges[MAXE];
int head[MAXN+5];
int Ecnt;

Edge redges[MAXE]; // grafo reverso para Kosaraju
int rhead[MAXN+5];

int N, E;

// Para SCC
int visited[MAXN+5];
int order[MAXN+5], ord_top;
int comp[MAXN+5], comp_cnt;

// DAG comprimido dos SCCs
Edge dag[ MAXE ];
int dhead[MAXN+5];
int dcnt;

// -----------------------------------------------------------
// Adiciona aresta no grafo
void add_edge(int u, int v, int w) {
    edges[Ecnt].to = v;
    edges[Ecnt].w = w;
    edges[Ecnt].next = head[u];
    head[u] = Ecnt;

    redges[Ecnt].to = u;
    redges[Ecnt].w = w;
    redges[Ecnt].next = rhead[v];
    rhead[v] = Ecnt;

    Ecnt++;
}

// -----------------------------------------------------------
// Kosaraju 1ª passagem (DFS normal)
void dfs1(int u) {
    visited[u] = 1;
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (!visited[v]) dfs1(v);
    }
    order[ord_top++] = u;
}

// -----------------------------------------------------------
// Kosaraju 2ª passagem (DFS reverso)
void dfs2(int u, int c) {
    comp[u] = c;
    for (int i = rhead[u]; i != -1; i = redges[i].next) {
        int v = redges[i].to;
        if (comp[v] == -1) dfs2(v, c);
    }
}

// -----------------------------------------------------------
// Monta DAG dos SCCs
void build_dag() {
    for (int i = 0; i < comp_cnt; i++) dhead[i] = -1;
    dcnt = 0;

    for (int u = 1; u <= N; u++) {
        int cu = comp[u];
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int cv = comp[v];
            if (cu != cv) {
                dag[dcnt].to = cv;
                dag[dcnt].w  = edges[i].w;
                dag[dcnt].next = dhead[cu];
                dhead[cu] = dcnt++;
            }
        }
    }
}

// -----------------------------------------------------------
// Dijkstra no DAG de SCCs
int dist[MAXN+5];
int visited_d[MAXN+5];

int pq[MAXN*10], pqd[MAXN*10]; // heap simples (min-heap)
int pqsz;

void push(int x, int d) {
    pq[++pqsz] = x;
    pqd[pqsz] = d;

    int i = pqsz;
    while (i > 1 && pqd[i] < pqd[i/2]) {
        int tx = pq[i], td = pqd[i];
        pq[i] = pq[i/2]; pqd[i] = pqd[i/2];
        pq[i/2] = tx; pqd[i/2] = td;
        i /= 2;
    }
}

int pop() {
    int ret = pq[1];
    pq[1] = pq[pqsz];
    pqd[1] = pqd[pqsz];
    pqsz--;

    int i = 1, l, r, small;
    while (1) {
        l = i*2;
        r = i*2+1;
        small = i;

        if (l <= pqsz && pqd[l] < pqd[small]) small = l;
        if (r <= pqsz && pqd[r] < pqd[small]) small = r;
        if (small == i) break;

        int tx = pq[i], td = pqd[i];
        pq[i] = pq[small]; pqd[i] = pqd[small];
        pq[small] = tx; pqd[small] = td;

        i = small;
    }
    return ret;
}

int dijkstra(int start, int end) {
    for (int i = 0; i < comp_cnt; i++) {
        dist[i] = INF;
        visited_d[i] = 0;
    }
    pqsz = 0;

    dist[start] = 0;
    push(start, 0);

    while (pqsz) {
        int u = pop();
        if (visited_d[u]) continue;
        visited_d[u] = 1;

        if (u == end) return dist[u];

        for (int i = dhead[u]; i != -1; i = dag[i].next) {
            int v = dag[i].to;
            int w = dag[i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }
    return INF;
}

// -----------------------------------------------------------
int main() {
    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        // Reset
        for (int i = 1; i <= N; i++) {
            head[i] = rhead[i] = -1;
        }
        Ecnt = 0;

        // Lê arestas
        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            add_edge(X, Y, H);
        }

        // Kosaraju para SCC
        memset(visited, 0, sizeof(visited));
        ord_top = 0;

        for (int i = 1; i <= N; i++)
            if (!visited[i]) dfs1(i);

        // Segunda passagem
        for (int i = 1; i <= N; i++) comp[i] = -1;

        comp_cnt = 0;
        for (int i = ord_top - 1; i >= 0; i--) {
            int u = order[i];
            if (comp[u] == -1) {
                dfs2(u, comp_cnt);
                comp_cnt++;
            }
        }

        // Montar DAG de SCCs
        build_dag();

        // Consultas
        int K;
        scanf("%d", &K);

        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);

            int cO = comp[O], cD = comp[D];

            if (cO == cD) {
                // Mesmo país → instantâneo
                printf("0\n");
                continue;
            }

            int ans = dijkstra(cO, cD);

            if (ans >= INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", ans);
        }

        printf("\n");
    }
    return 0;
}
