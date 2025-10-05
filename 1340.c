/* Kauan Dias Caisley AED 1 Eu posso adivinhas a estrutura de dados!*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Implementação simples de pilha
typedef struct {
    int info[MAX];
    int top;
} Stack;

void init_stack(Stack *s) { 
    s->top = 0;
}

void push(Stack *s, int x) {
    s->info[s->top++] = x;
}

int pop_stack(Stack *s) {
    return s->info[--s->top];
}

int peek_stack(Stack *s) {
    return s->info[s->top - 1];
}

int empty_stack(Stack *s) {
    return s->top == 0;
}

// Implementação simples de fila
typedef struct {
    int info[MAX];
    int front, rear;
} Queue;

void init_queue(Queue *q) {
    q->front = q->rear = 0;
}

void enqueue(Queue *q, int x) {
    q->info[q->rear++] = x;
}

int dequeue(Queue *q) {
    return q->info[q->front++];
}

int front_queue(Queue *q) {
    return q->info[q->front];
}

int empty_queue(Queue *q) {
    return q->front == q->rear;
}

// Fila de prioridade (máximo primeiro)
typedef struct {
    int info[MAX];
    int size;
} PQueue;

void init_pq(PQueue *pq) {
    pq->size = 0;
}

void push_pq(PQueue *pq, int x) {
    pq->info[pq->size++] = x;
}

int pop_pq(PQueue *pq) {
    int i, max_i = 0;
    for (i = 1; i < pq->size; i++)
        if (pq->info[i] > pq->info[max_i])
            max_i = i;
    int val = pq->info[max_i];
    pq->info[max_i] = pq->info[--pq->size];
    return val;
}

int top_pq(PQueue *pq) {
    int i, max_i = 0;
    for (i = 1; i < pq->size; i++)
        if (pq->info[i] > pq->info[max_i])
            max_i = i;
    return pq->info[max_i];
}

int empty_pq(PQueue *pq) {
    return pq->size == 0;
}

int main() {
    int n; 
    while (scanf("%d", &n) != EOF) { // enquanto houver casos de teste
        Stack s; Queue q; PQueue pq; // inicializando as estruturas
        init_stack(&s);
        init_queue(&q);
        init_pq(&pq);

        int is_stack = 1, is_queue = 1, is_pq = 1; // assumindo que todas são possíveis até provar o contrário

        for (int i = 0; i < n; i++) {
            int op, x; 
            scanf("%d %d", &op, &x);

            if (op == 1) { // op == 1 significa inserção
                push(&s, x); 
                enqueue(&q, x);
                push_pq(&pq, x);
            } else { // op == 2
                if (empty_stack(&s) || peek_stack(&s) != x)
                    is_stack = 0; // se a pilha está vazia ou o topo não é x, não é pilha
                else
                    pop_stack(&s); // remove o topo

                if (empty_queue(&q) || front_queue(&q) != x)
                    is_queue = 0; // se a fila está vazia ou a frente não é x, não é fila
                else
                    dequeue(&q); // remove a frente

                if (empty_pq(&pq) || top_pq(&pq) != x) // se a fila de prioridade está vazia ou o topo não é x, não é fila de prioridade
                    is_pq = 0;
                else
                    pop_pq(&pq); // remove o topo
            }
        }

        int possible = is_stack + is_queue + is_pq; // contando quantas estruturas ainda são possíveis
        if (possible == 0) // nenhuma é possível
            printf("impossible\n");
        else if (possible > 1) // mais de uma é possível
            printf("not sure\n");
        else if (is_stack) // só a pilha é possível
            printf("stack\n");
        else if (is_queue) // só a fila é possível
            printf("queue\n");
        else
            printf("priority queue\n");
    }
    return 0;
}
