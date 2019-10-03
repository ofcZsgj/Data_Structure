#include <stdio.h>

typedef int ElementType;
typedef int SetName;
typedef struct set* SetType;

struct set{
    ElementType parent;
};

SetName Find(SetType S, ElementType X){

    if(S[X].parent < 0){
        return X;
    }
    //路径压缩
    else return S[X].parent = Find(S, S[X].parent);

}

void Union(SetType S, ElementType x, ElementType y){

    int index1, index2;
    index1 = Find(S, x);
    index2 = Find(S, y);

    //按秩归并
    if(S[index1].parent >= S[index2].parent){
        S[index1].parent += S[index2].parent;
        S[index2].parent = index1;
    }
    else {
        S[index2].parent += S[index1].parent;
        S[index1].parent = index2;
    }

}