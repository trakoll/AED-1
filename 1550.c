/* Kauan Dias Caisley ARED 1 Inversão*/

#include <stdio.h>

int rev_num(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int min_presses(int A, int B) {
    const int MAXN = 10000;      // limite superior (inclusive)
    static int vis[10001];       // reutilizado entre chamadas
    static int dist[10001];
    static int q[20000];         // fila (suficiente)
    int head = 0, tail = 0;

    // inicializa visitados/distâncias para este caso
    for (int i = 0; i <= MAXN; i++) vis[i] = 0;

    // inicia BFS
    q[tail++] = A;
    vis[A] = 1;
    dist[A] = 0;

    while (head < tail) {
        int u = q[head++];

        if (u == B) return dist[u];

        // operação +1
        if (u + 1 <= MAXN && !vis[u + 1]) {
            vis[u + 1] = 1;
            dist[u + 1] = dist[u] + 1;
            q[tail++] = u + 1;
        }

        // operação reverse
        int r = rev_num(u);
        if (r <= MAXN && !vis[r]) {
            vis[r] = 1;
            dist[r] = dist[u] + 1;
            q[tail++] = r;
        }
    }

    return -1; // não esperado
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", min_presses(A, B));
    }

    return 0;
}
