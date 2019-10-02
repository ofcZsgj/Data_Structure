#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef List Postion;

struct Node{
    int data;
    PtrToNode next;
};

int IsEmpty(List L){

    return L->next == NULL;

}

int IsLast(Postion P, List L){
    return P->next == NULL;
}

Postion Find(int data, List L){

    Postion p = L->next;//asumes a header

    while(p != NULL && p->data != data){
        p = p->next;
    }

    return p;

}

Postion FindPrevious(int data, List L){

    Postion p = L;

    while(p->next != NULL && p->next->data != data){
        p = p->next;
    }

    return p;

}

void Delete(int data, List L){

    Postion p, tmp;
    p = FindPrevious(data, L);

    //assumption of header use
    if( !IsLast(p, L) ){
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }

}

void Insert(Postion P, int data, List L){

    Postion tmp;
    tmp = (Postion)malloc(sizeof(Postion));
    if(!tmp){
        printf("Out Of Space\n");
        return;
    }

    tmp->data = data;
    tmp->next = P->next;
    P->next = tmp;

}

void DeleteList(List L){

    Postion p, tmp;
    p = L->next;//headed assumed

    L->next = NULL;

    while(p){

        tmp = p;
        free(p);
        p = tmp->next;

    }

}

int main(){
    return 0;
}