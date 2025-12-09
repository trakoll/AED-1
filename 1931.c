/* Kauan Dias Caisley AED 1 Mania de Par*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 0x3f3f3f3f // infinito

// grafo
typedef struct {
    int v, w;
} Aresta;

typedef struct {
    Aresta *Arestas;
    int tam, cap;
} vet;

vet adj[200005];  // até 2*C

void vet_init(vet *v) {
    v->tam = 0;
    v->cap = 2;
    v->Arestas = malloc(sizeof(Aresta) * v->cap);
}

void vet_push(vet *v, int vert, int w) {
    if (v->tam == v->cap) {
        v->cap *= 2;
        v->Arestas = realloc(v->Arestas, sizeof(Aresta) * v->cap);
    }
    v->Arestas[v->tam].v = vert;
    v->Arestas[v->tam].w = w;
    v->tam++;
}

// Min-Heap

typedef struct {
    int v;
    int dist;
} Node;

Node heap[400005];
int heap_tam = 0;
int pos[400005]; // posição do nó na heap
int distv[400005];

void swap(int a, int b) {
    Node tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;

    pos[heap[a].v] = a;
    pos[heap[b].v] = b;
}

void heap_up(int i) {
    while (i > 1) {
        int p = i / 2;
        if (heap[p].dist <= heap[i].dist) break;
        swap(p, i);
        i = p;
    }
}

void heap_down(int i) {
    while (1) {
        int l = i * 2, r = l + 1, small = i;
        if (l <= heap_tam && heap[l].dist < heap[small].dist) small = l;
        if (r <= heap_tam && heap[r].dist < heap[small].dist) small = r;
        if (small == i) break;
        swap(i, small);
        i = small;
    }
}

void heap_push(int v, int d) {
    if (pos[v] == 0) { // novo
        heap_tam++;
        heap[heap_tam].v = v;
        heap[heap_tam].dist = d;
        pos[v] = heap_tam;
        heap_up(heap_tam);
    } else { // já existe: relaxamento
        int i = pos[v];
        heap[i].dist = d;
        heap_up(i);
    }
}

Node heap_pop() {
    Node ret = heap[1];
    pos[ret.v] = 0;

    heap[1] = heap[heap_tam];
    pos[heap[1].v] = 1;
    heap_tam--;

    heap_down(1);
    return ret;
}

int main() {
    int C, V;
    scanf("%d %d", &C, &V);

    int N = 2 * C;

    for (int i = 1; i <= N; i++)
        vet_init(&adj[i]);

    for (int i = 0; i < V; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        int a0 = a;
        int a1 = a + C;
        int b0 = b;
        int b1 = b + C;

        // alternância de paridade
        vet_push(&adj[a0], b1, w);
        vet_push(&adj[b0], a1, w);
        vet_push(&adj[a1], b0, w);
        vet_push(&adj[b1], a0, w);
    }

    // Dijkstra
    for (int i = 1; i <= N; i++) {
        distv[i] = INF;
        pos[i] = 0;
    }

    int start = 1;  // cidade 1 com paridade 0
    int goal  = C;  // cidade C com paridade 0

    distv[start] = 0;
    heap_push(start, 0);

    while (heap_tam > 0) {
        Node nd = heap_pop();
        int u = nd.v;
        int d = nd.dist;

        if (d != distv[u]) continue;
        if (u == goal) break;

        for (int i = 0; i < adj[u].tam; i++) {
            int v = adj[u].Arestas[i].v;
            int w = adj[u].Arestas[i].w;
            if (distv[v] > d + w) {
                distv[v] = d + w;
                heap_push(v, distv[v]);
            }
        }
    }

    if (distv[goal] == INF) printf("-1\n");
    else printf("%d\n", distv[goal]);

    return 0;
}
