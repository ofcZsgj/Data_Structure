#include <stdio.h>

#define ElementType int
#define MaxSize 100

struct set{
    ElementType data;
    int parent;
};
typedef struct set* SetType;

int Find(SetType S, ElementType item){

    int i = 0, parent;
    for(; i < MaxSize && S->data != item; ++i);

    if(i >= MaxSize){
        return -1;
    }

    for(; S[i].parent >= 0; i = S[i].parent);

    return i;

}

void Union(SetType S, ElementType x, ElementType y){

    int index1, index2;
    index1 = Find(S, x);
    index2 = Find(S, y);

    if(S[index1].parent > S[index2].parent){
        S[index1].parent += S[index2].parent;
        S[index2].parent = index1;
    }
    else if(S[index1].parent < S[index2].parent){
        S[index2].parent += S[index1].parent;
        S[index1].parent = index2;
    }
    else return;

}