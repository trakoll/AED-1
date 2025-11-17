#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char info;
    struct No *es, *di;
} No;

No* criar_no(char info) {
    No *n = malloc(sizeof(No));
    n->info = info;
    n->es = n->di = NULL;
    return n;
}

void inserir(No **a, char info) {
    if (*a == NULL) {
        *a = criar_no(info);
        return;
    }
    if (info < (*a)->info) inserir(&(*a)->es, info);
    else inserir(&(*a)->di, info);
}

void prefixa(No *a, int *first) {
    if (a == NULL) return;
    if (!(*first)) printf(" "); // se não for o primeiro, imprime espaço
    printf("%c", a->info);
    *first = 0; // marca que já imprimiu o primeiro
    prefixa(a->es, first);
    prefixa(a->di, first);
}

void infixa(No *a, int *first) {
    if (a == NULL) return;
    infixa(a->es, first);
    if (!(*first)) printf(" ");
    printf("%c", a->info);
    *first = 0;
    infixa(a->di, first);
}

void posfixa(No *a, int *first) {
    if (a == NULL) return;
    posfixa(a->es, first);
    posfixa(a->di, first);
    if (!(*first)) printf(" ");
    printf("%c", a->info);
    *first = 0;
}

void pesquisar(No *a, char info) {
    if (a == NULL) printf("%c nao existe\n", info);
    else if (a->info == info) printf("%c existe\n", info);
    else if (info < a->info) pesquisar(a->es, info);
    else pesquisar(a->di, info);
}

void liberar(No *a) {
    if (a != NULL) {
        liberar(a->es);
        liberar(a->di);
        free(a);
    }
}

int main() {
    char comando[20];
    No *raiz = NULL;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            char x;
            scanf(" %c", &x);
            inserir(&raiz, x);
        }
        else if (strcmp(comando, "P") == 0) {
            char x;
            scanf(" %c", &x);
            pesquisar(raiz, x);
        }
        else if (strcmp(comando, "INFIXA") == 0) {
            int first = 1;
            infixa(raiz, &first);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0) {
            int first = 1;
            prefixa(raiz, &first);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0) {
            int first = 1;
            posfixa(raiz, &first);
            printf("\n");
        }
    }

    liberar(raiz);
    return 0;
}
