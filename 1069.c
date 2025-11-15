/* Kauan Dias Caisley AED 1 Diamantes e Areia*/

#include <stdio.h>
#include <stdlib.h>

void pop (int *topo){
        (*topo)--;
}

void push (int *topo, char *pilha, char c){
    pilha[++(*topo)] = c;
}

int countdiamante (char *stringcerta){ // conta os diamantes
    int count = 0, topo = -1;
    char pilha[1001];

    for (int i = 0; stringcerta[i] != '\0'; i++){
        if (stringcerta[i] == '<'){ // se abre o diamente, empilha
            push (&topo, pilha, stringcerta[i]);
        }
        else if (stringcerta[i] == '>'){ // se fecha o diamante
            if (topo != -1){ // e tem pelo menos 1 aberto
                pop (&topo); // desempilha
                count++; // e fecha 1 diamente
            }
        }
    }

    return count;
}

int main (){
    int N, count;
    char sting[1001], stringcerta[1001];

    scanf ("%d", &N); // número de casos

    for (int i = 0; i < N; i++){
        count = 0;

        scanf ("%s", sting); // leitura da string

        for (int j = 0; sting[j] != '\0'; j++){
            if (sting[j] != '.'){
                stringcerta[count] = sting[j]; // "limpando" a areia
                count++;
            }
            stringcerta[count] = '\0';
        }

        printf ("%d\n", countdiamante (stringcerta)); // conta os diamantes na string limpa (não precisava limpar, mas ok......)
    }

    return 0;
}