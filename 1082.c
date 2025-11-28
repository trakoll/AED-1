/* Kauan Dias Caisley AED 1 Componentes Conexos*/

#include <stdio.h>

int adj[26][26];    // matriz de adjacência (máx 26 vértices)
int vis[26];        // visitado
int comp[26];       // armazena indices de um componente
int comp_sz;

// DFS recursiva
void dfs(int u, int V) {
    vis[u] = 1;
    comp[comp_sz++] = u;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !vis[v]) dfs(v, V);
    }
}

// ordena comp[0..comp_sz-1] em ordem crescente (selection sort)
void sort_comp() {
    for (int i = 0; i < comp_sz - 1; i++) {
        int minp = i;
        for (int j = i + 1; j < comp_sz; j++) {
            if (comp[j] < comp[minp]) minp = j;
        }
        if (minp != i) {
            int t = comp[i]; comp[i] = comp[minp]; comp[minp] = t;
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int tc = 1; tc <= T; tc++) {
        int V, E;
        scanf("%d %d", &V, &E);

        // inicializa
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (int j = 0; j < V; j++) adj[i][j] = 0;
        }

        // lê as arestas
        for (int i = 0; i < E; i++) {
            char a, b;
            // leitura tolerante a espaços/novas linhas entre os caracteres
            scanf(" %c %c", &a, &b);
            int u = a - 'a';
            int v = b - 'a';
            if (u >= 0 && u < V && v >= 0 && v < V) {
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
        }

        // imprime cabeçalho do caso
        printf("Case #%d:\n", tc);

        int components = 0;

        // percorre os vértices em ordem; ao encontrar não visitado, obtém componente
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                comp_sz = 0;
                dfs(i, V);
                // ordena vértices do componente (para garantir ordem crescente)
                sort_comp();

                // imprime vértices do componente separados por vírgula e com vírgula no final
                for (int k = 0; k < comp_sz; k++) {
                    char ch = 'a' + comp[k];
                    printf("%c,", ch);
                    if (k + 1 < comp_sz) printf(""); // só para ficar no estilo; sem efeito
                }
                printf("\n");
                components++;
            }
        }

        // imprime número de componentes (em inglês)
        printf("%d connected components\n\n", components);
    }

    return 0;
}
