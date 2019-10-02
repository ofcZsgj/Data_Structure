#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MaxHeap Heap
#define MinHeap Heap
#define MaxData 999

struct HNode{
    ElementType* data;
    int size;
    int capacity;
};
typedef struct HNode* Heap;

Heap CreateHeap(int max_size){

    Heap H = (Heap)malloc(sizeof(Heap));
    if(!H){
        printf("Out Of Space\n");
        return NULL;
    }

    H->data = (ElementType*)malloc(sizeof(ElementType) * (max_size + 1));
    if(!H->data){
        printf("Out Of Space\n");
        return NULL;
    }

    
    H->data[0] = MaxData;
    H->size = 0;
    H->capacity = max_size;

    return H;

}

void InsertMaxHeap(Heap H, ElementType item){

    if(!H){
        return;
    }

    int i = ++(H->size);

    for(; H->data[i/2] < item; i /= 2){

        H->data[i] = H->data[i/2]; 

    }

    H->data[i] = item;

}

int IsEmpty(Heap H){

    if(H){
        return H->size == 0;
    }
    else return 1;

}

//delete the last element & return
ElementType Delete(Heap H, ElementType item){

    if(IsEmpty(H)){
        return -1;
    }
    
    int child, parent;
    ElementType max_item, tmp;

    max_item = H->data[1];
    tmp = H->data[H->size--];
    for(parent = 1; parent * 2 <= H->size; parent = child){

        child = parent * 2;

        //(child != H->size) == 0 : no right sub node
        if((child != H->size) && H->data[child] < H->data[child+1]){
            ++child;
        }

        if(tmp >= H->data[child]){
            break;
        }
        else{
            H->data[parent] = H->data[child];
        }

    }

    H->data[parent] = tmp;
    return max_item;

}

/***********************************************************************************/
void PercDown(Heap H, int p){

    int parent, child;
    ElementType tmp;

    tmp = H->data[p];

    for(parent = p; parent * 2 <= H->size; parent = child){
        
        child = parent * 2;
        if((child != H->size) && H->data[child] < H->data[child+1]){
            ++child;
        }
        if(tmp >= H->data[child]){
            break;
        }
        else{
            H->data[parent] = H->data[child];
        }
    }

    H->data[parent] = tmp;

}

Heap BulidMaxHeap(MaxHeap H){

    int i = H->size;
    for(i = H->size / 2; i > 0; --i){
        PercDown(H, i);
    }

    return H;

}
/***********************************************************************************/