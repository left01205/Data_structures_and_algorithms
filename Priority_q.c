#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

void initialize(PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue* pq) {
    return pq->size == MAX_SIZE;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = pq->size - 1;
    while (i >= 0 && pq->elements[i].priority > newElement.priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }

    pq->elements[i + 1] = newElement;
    pq->size++;
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = pq->elements[0].data;

    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }

    pq->size--;

    return data;
}

int main() {
    PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);

    printf("Dequeued element: %d\n", dequeue(&pq));
    printf("Dequeued element: %d\n", dequeue(&pq));
    printf("Dequeued element: %d\n", dequeue(&pq));

    return 0;
}