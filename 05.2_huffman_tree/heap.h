#include <stdio.h>
#include <stdlib.h>

#define ElementType HuffmanTree
#define MaxHeap Heap
#define MinHeap Heap
#define MaxData 999

struct TNode{
    int weight;
    struct TNode* left;
    struct TNode* right;
};
typedef struct TNode* HuffmanTree;

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

    
    H->data[0] = NULL;
    H->size = 0;
    H->capacity = max_size;

    return H;

}

void InsertMaxHeap(Heap H, ElementType item){

    if(!H){
        return;
    }

    int i = ++(H->size);

    for(; H->data[i/2]->weight < item->weight; i /= 2){

        H->data[i]->weight = H->data[i/2]->weight; 

    }

    H->data[i]->weight = item->weight;

}

void InsertMinHeap(Heap H, ElementType item){

    if(!H){
        return;
    }

    int i = ++(H->size);

    for(; H->data[i/2]->weight > item->weight; i /= 2){

        H->data[i]->weight = H->data[i/2]->weight; 

    }

    H->data[i]->weight = item->weight;

}

int IsEmpty(Heap H){

    if(H){
        return H->size == 0;
    }
    else return 1;

}

//delete the max element & return
ElementType DeleteMax(Heap H){

    if(IsEmpty(H)){
        return NULL;
    }
    
    int child, parent;
    ElementType max_item;
    ElementType tmp;

    max_item = H->data[1];
    tmp = H->data[H->size--];
    for(parent = 1; parent * 2 <= H->size; parent = child){

        child = parent * 2;

        //(child != H->size) == 0 : no right sub node
        if((child != H->size) && H->data[child]->weight < H->data[child+1]->weight){
            ++child;
        }

        if(tmp->weight >= H->data[child]->weight){
            break;
        }
        else{
            H->data[parent]->weight = H->data[child]->weight;
        }

    }

    H->data[parent]->weight = tmp->weight;
    return max_item;

}

//delete the min element & return
ElementType DeleteMin(Heap H){

    if(IsEmpty(H)){
        return NULL;
    }
    
    int child, parent;
    ElementType min_item;
    ElementType tmp;

    min_item = H->data[1];
    tmp = H->data[H->size--];
    for(parent = 1; parent * 2 <= H->size; parent = child){

        child = parent * 2;

        //(child != H->size) == 0 : no right sub node
        if((child != H->size) && H->data[child]->weight > H->data[child+1]->weight){
            ++child;
        }

        if(tmp->weight <= H->data[child]->weight){
            break;
        }
        else{
            H->data[parent]->weight = H->data[child]->weight;
        }

    }

    H->data[parent]->weight = tmp->weight;
    return min_item;

}

/***********************************************************************************/
void PercDown(MaxHeap H, int p){

    int parent, child;
    ElementType tmp;

    tmp = H->data[p];

    for(parent = p; parent * 2 <= H->size; parent = child){
        
        child = parent * 2;
        if((child != H->size) && H->data[child]->weight < H->data[child+1]->weight){
            ++child;
        }
        if(tmp->weight >= H->data[child]->weight){
            break;
        }
        else{
            H->data[parent]->weight = H->data[child]->weight;
        }
    }

    H->data[parent]->weight = tmp->weight;

}

Heap BulidMaxHeap(MaxHeap H){

    int i = H->size;
    for(i = H->size / 2; i > 0; --i){
        PercDown(H, i);
    }

    return H;

}
/***********************************************************************************/

/***********************************************************************************/
void PercDown2(MinHeap H, int p){

    int parent, child;
    ElementType tmp;

    tmp = H->data[p];

    for(parent = p; parent * 2 <= H->size; parent = child){
        
        child = parent * 2;
        if((child != H->size) && H->data[child]->weight > H->data[child+1]->weight){
            ++child;
        }
        if(tmp->weight <= H->data[child]->weight){
            break;
        }
        else{
            H->data[parent]->weight = H->data[child]->weight;
        }
    }

    H->data[parent]->weight = tmp->weight;

}

Heap BulidMinHeap(MinHeap H){

    int i = H->size;
    for(i = H->size / 2; i > 0; --i){
        PercDown2(H, i);
    }

    return H;

}
/***********************************************************************************/