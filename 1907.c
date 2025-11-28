/* Kauan Dias Caisley - AED 1 Coloração de Cenários de Jogos */

#include <stdio.h>

// matriz da imagem
char img[1024][1024];

// matriz de visitados
int visitado[1024][1024];

// resolução da imagem
int N, M;

// filas para BFS
int fila_x[2000000];
int fila_y[2000000];

// BFS para marcar toda uma região branca conectada a partir de (sx, sy)
void bfs(int sx, int sy) {
    int ini = 0, fim = 0;

    // coloca o pixel inicial na fila
    fila_x[fim] = sx;
    fila_y[fim] = sy;
    fim++;

    visitado[sx][sy] = 1;  // marca como visitado

    // movimentação 4-direções
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // enquanto existir pixel na fila
    while (ini < fim) {

        int x = fila_x[ini];
        int y = fila_y[ini];
        ini++;

        // verifica os 4 vizinhos
        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            // verifica se está dentro da imagem
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {

                // se for branco e ainda não visitado
                if (!visitado[nx][ny] && img[nx][ny] == '.') {

                    visitado[nx][ny] = 1;  // marca como visitado
                    fila_x[fim] = nx;      // adiciona à fila
                    fila_y[fim] = ny;
                    fim++;
                }
            }
        }
    }
}

int main() {

    // lê N e M
    scanf("%d %d", &N, &M);

    // lê a imagem
    for (int i = 0; i < N; i++) {
        scanf("%s", img[i]);
    }

    int cliques = 0;

    // percorre todos os pixels
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            // achou um pixel branco ainda não visitado → nova região
            if (img[i][j] == '.' && !visitado[i][j]) {
                cliques++;       // um clique necessário
                bfs(i, j);       // marca toda a região
            }
        }
    }

    // imprime número total de regiões brancas
    printf("%d\n", cliques);

    return 0;
}
