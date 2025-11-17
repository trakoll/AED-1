/* Kauan Dias Caisley ARD 1 Árvore Binária de Busca*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *es;
    struct No *di;
} No;

typedef struct{
    No *raiz;
} arvore;

void inserir_recursivo(No **a, int info){
    if (*a == NULL){ // subárvore vazia
        No *novo = (No*) malloc(sizeof(No));
        novo->info = info;
        novo->es = NULL;
        novo->di = NULL;
        *a = novo; 
    }
    else{
        if (info < (*a)->info){
            inserir_recursivo(&(*a)->es, info); // envia o endereço do ponteiro esquerdo
        }
        else{
            inserir_recursivo(&(*a)->di, info); // envia o endereço do ponteiro direito
        }
    }
}

void pre_ordem (No *a){
    if (a != NULL){
        printf (" %d", a->info);
        pre_ordem (a->es);
        pre_ordem (a->di);
    }
}

void in_ordem (No *a){
    if (a != NULL){
        in_ordem (a->es);
        printf (" %d", a->info);
        in_ordem (a->di);
    }
}

void post_ordem (No *a){
    if (a != NULL){
        post_ordem (a->es);
        post_ordem (a->di);
        printf (" %d", a->info);
    }
}

void libera_arvore (No *a){
    if (a != NULL){
        libera_arvore (a->es);
        libera_arvore (a->di);
        free (a);
    }
}

int main (){
    arvore *a = (arvore*) malloc (sizeof(arvore));
    a->raiz = NULL;
    int c, n, info;

    scanf ("%d", &c); // número de casos
    getchar();

    for (int i = 0; i < c; i++){
        scanf ("%d", &n); // número de nós
        getchar();

        for (int j = 0; j < n; j++){
            scanf ("%d", &info); // info a ser inserido
            
            
            inserir_recursivo (&(a->raiz), info);
        }

        printf ("Case %d:\n", i+1);
        printf ("Pre.:");
        pre_ordem (a->raiz);
        printf ("\nIn..:");
        in_ordem (a->raiz);
        printf ("\nPost:");
        post_ordem (a->raiz);
        printf ("\n\n");

        libera_arvore (a->raiz);
        a->raiz = NULL;
    }

    free (a);
    return 0;
}