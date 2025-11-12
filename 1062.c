/* Kauan Dias Caisley AED 1 Trilhos*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {

        while (1) {

            int alvo[1000];
            scanf("%d", &alvo[0]);

            if (alvo[0] == 0) { // fim do bloco
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++)
                scanf("%d", &alvo[i]);

            int pilha[1000];
            int topo = -1;
            int atual = 1; // próximo vagão a entrar
            int possivel = 1;

            for (int i = 0; i < n; i++) {
                int target = alvo[i];
                // empilha até que o topo seja igual ao desejado
                while (atual <= n && (topo == -1 || pilha[topo] != target)) {
                    pilha[++topo] = atual++;
                }
                // verifica se o topo é o desejado
                if (pilha[topo] == target) {
                    topo--; // desempilha
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }

    }
    return 0;
}
