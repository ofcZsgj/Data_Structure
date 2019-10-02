#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int* data;
    int max_size;
    int top;
};

typedef struct Stack* Stack;

Stack CreateStack(int max_size){

    Stack S = (Stack)malloc(sizeof(Stack));  
    if(!S){
        printf("Out Of Space\n");
        return NULL;
    }

    S->data = (int*)malloc(sizeof(int) * max_size);
    if(!S->data){
        printf("Out Of Space\n");
        return NULL;
    }

    S->max_size = max_size;
    S->top = -1;

    return S;

}

int IsEmtpy(Stack S){

    return S->top == -1;

}

void Push(Stack S, int data){

    if(!S){
        printf("CreateStack First\n");
        return;
    }

    S->data[++(S->top)] = data;

}

int Pop(Stack S){

    if(!S){
        printf("CreateStack First\n");
        exit(1);
    }

    if(IsEmtpy(S)){
        printf("Stack is Empty\n");
        exit(1);
    }

    return S->data[(S->top)--];

}

void MakeEmpty(Stack S){

    if(!S){
        printf("CreateStack First\n");
        exit(1);
    }

    while(!IsEmtpy(S)){
        Pop(S);
    }

}

int main(){
    return 0;
}