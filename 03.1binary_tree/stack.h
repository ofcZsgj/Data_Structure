#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

struct Node{
    void* data;
    PtrToNode next;
};

int IsEmpty(Stack S){

    return S->next == NULL;

}

void* Pop(Stack S){

    if(IsEmpty(S)){
        printf("Stack is empty\n");
        exit(1);
    }

    PtrToNode tmp;
    tmp = S->next;

    S->next = tmp->next;
    void* data = tmp->data;
    free(tmp);

    return data;

}

void push(Stack S, void* data){

    PtrToNode tmp;
    tmp = (PtrToNode)malloc(sizeof(PtrToNode));
    if(!tmp){
        printf("Out Of Space\n");
        return;
    }

    tmp->data = data;
    tmp->next = S->next;
    S->next = tmp;

}


void MakeEmpty(Stack S){

    if( !S ){
        printf("Must Use CreateStack First\n");
        return;
    }

    while( !IsEmpty(S) ){
        Pop(S);
    }

}

Stack CreateStack(){

    Stack S = (Stack)malloc(sizeof(Stack));
    if(!S){
        printf("Out Of Space\n");
        return NULL;
    }

    S->data = NULL;
    S->next = NULL;

    return S;

}
