#include <stdio.h>

#define ElementType int

struct Node;
typedef struct Node* List;

struct Node{
    ElementType data;
    List next;
};

List Reverse(List L){

    if(!L){
        return NULL;
    }
    if(!L->next){
        return L;
    }
    //no header
    List new, old, tmp;
    new = L;
    old = new->next;

    while(old){

        tmp = old->next;
        old->next = new;

        new = old;
        old = tmp;

    }

    L = new;
    L->next = old;

    return L;

}

