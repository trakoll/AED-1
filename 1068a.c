/* Kauan Dias Caisley AED 1 Balanço de Parênteses I com vetor*/

#include <stdio.h>
#include <string.h>

int main() {
    char conta[1000];
    char pilha[1000];
    int topo;

    while (fgets(conta, sizeof(conta), stdin)) {
        topo = -1; // pilha vazia
        int incorreto = 0; // flag para indicar se a conta tá incorreta

        for (int i = 0; conta[i] != '\0'; i++) {
            char c = conta[i];

            if (c == '(') {
                // empilha
                if (topo < 1000 - 1)
                    pilha[++topo] = c;
            } else if (c == ')') {
                // desempilha
                if (topo == -1) { // não fechou
                    incorreto = 1;
                    break;
                } else {
                    topo--;
                }
            }
        }

        // se pilha não tá vazia ou houve erro, incorreto
        if (incorreto || topo != -1)
            printf("incorrect\n");
        else // tudo certo
            printf("correct\n");
    }

    return 0;
}