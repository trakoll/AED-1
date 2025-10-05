/* Kauan Dias Caisley AED 1 Menor e Posição com estrutura de dados*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
} no;

typedef struct lista{
    no *head;
} lista;

void novo_no(lista *l, int valor){
    no *novo = (no *) malloc (sizeof(no));

    novo->info = valor;
    novo->prox = l->head;

    l->head = novo;
}

void free_lista(lista *l){
    no *atual = l->head;
    no *prox;

    while (atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(l);
}

void encontrar_menor (lista *l, int *menor, int *posicao){
    no *atual = l->head;
    int indice = 0;

    // como n obrigatoriamente é maior que 0, o primeiro valor lido é o menor até o momento

    *menor = atual->info;
    *posicao = indice;
    atual = atual->prox;
    indice++;


    while (atual != NULL){
        if (atual->info < *menor){
            *menor = atual->info;
            *posicao = indice;
        }
        atual = atual->prox;
        indice++;
    }
}

int main (){
    int n, menor, posicao, valor; // definindo variaveis
    lista *vetor; // definindo o vetor como uma lista de nós

    vetor = (lista *) malloc (sizeof (lista)); // alocando dinamicamente a lista
    vetor->head = NULL; // inicializando a cabeça da lista como NULL

    scanf("%d", &n);

    if (n < 1 || n > 1000) return 1; // tamanhos inválidos do vetor

    for (int i = 0; i < n; i++){ // lendo os valores do vetor
        scanf("%d", &valor);

        novo_no(vetor, valor); // adicionando o valor lido na lista
    }

    // também funcionaria se eu fizesse a mesma lógica do 1180a e 1180b, mas decidi fazer uma função separada para encontrar o menor e a posição

    encontrar_menor(vetor, &menor, &posicao); // encontrando o menor valor e sua posição

    posicao = n - 1 - posicao; // como os valores foram inseridos no início da lista, a posição dentro do vetor seria n - 1 - posicao

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free_lista(vetor); // liberando a memória alocada

    return 0;
}

