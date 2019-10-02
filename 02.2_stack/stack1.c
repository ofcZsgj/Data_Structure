#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

struct Node{
    int data;
    PtrToNode next;
};

int IsEmpty(Stack S){

    return S->next == NULL;

}

int Pop(Stack S){

    if(IsEmpty(S)){
        printf("Stack is empty\n");
        exit(1);
    }

    PtrToNode tmp;
    tmp = S->next;

    S->next = tmp->next;
    int data = tmp->data;
    free(tmp);

    return data;

}

void push(Stack S, int data){

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

int Top(Stack S){

    if( !IsEmpty(S) ){
        return S->next->data;
    }

    //Error("Empty Stack");
    return 0;//return value used to avoid warning

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

    S->next = NULL;

    return S;

}

int main(){
    return 0;
}