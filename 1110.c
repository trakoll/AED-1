/* Kauan Dias Caisley AED 1 Jogando Cartas Fora*/

#include <stdio.h>
#include <stdlib.h>

void push (int *topo, int *pilha, int n){
    pilha[++(*topo)] = n;
}

void pop (int *topo){
    (*topo)--;
}

void cartas_fora (int *pilha, int *topo){
    while (*topo > 0){
        
        printf ("%d", pilha[*topo]);

        if (*topo > 1){
            printf (", ");
        }

        pop (topo); // descarta a carta do topo

        // move a próxima carta para o final da pilha
        int carta = pilha[*topo];
        for (int i = *topo; i > 0; i--){ // move toda a pilha pra cima
            pilha[i] = pilha[i-1];
        }
        pilha[0] = carta; // coloca a carta no final
    }
}

int main (){
    int n, pilha[50], topo = -1;

    scanf ("%d", &n); // número de cartas

    while (n != 0){
        for (int i = n; i >= 1; i--){
            push (&topo, pilha, i); // empilha as cartas, deixando n na base
        }

        printf ("Discarded cards: ");
        cartas_fora (pilha, &topo);
        printf ("\nRemaining card: %d\n", pilha[topo]); // imprime a última carta restante

        topo = -1; // reseta a pilha para o próximo caso
        scanf ("%d", &n); // lê o próximo número de cartas
    }


    return 0;
}