#include <stdio.h>
#include <stdlib.h>

struct QNode{
    void** data;
    int max_size;
    int front;
    int rear;
};

typedef struct QNode* Queue;

Queue CreateQueue(int max_size){

    Queue Q;
    Q = (Queue)malloc(sizeof(Queue));
    if(!Q){
        printf("Out Of Space\n");
        return NULL;
    }

    Q->data = (void**)malloc(sizeof(void*) * max_size);
    if(!Q->data){
        printf("Out Of Space\n");
        return NULL;
    }

    Q->max_size = max_size;
    Q->front = 0;
    Q->rear = 0;

    return Q;

}

int IsEmpty(Queue Q){

    return Q->rear == Q->front;

}

int IsFull(Queue Q){

    return ((Q->rear + 1) % Q->max_size) == Q->front;

}

void Enqueue(Queue Q, void** data){

    if(IsFull(Q)){
        printf("Queue is full\n");
        return;
    }

    Q->rear = (Q->rear + 1) % Q->max_size;
    Q->data[Q->rear] = *data;

}

void* Dequeue(Queue Q){

    if(IsEmpty(Q)){
        printf("Queue is empty\n");
        exit(1);
    }

    Q->front = (Q->front + 1) % Q->max_size;
    return Q->data[Q->front];

}