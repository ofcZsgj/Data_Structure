#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HuffmanTree Huffman(MinHeap H){

    int i;
    HuffmanTree T;

    BulidMinHeap(H);

    for(i = 1; i < H->size; ++i){

        T = (HuffmanTree)malloc(sizeof(HuffmanTree));

        T->left = DeleteMin(H);
        T->right = DeleteMin(H);
        T->weight = T->left->weight + T->right->weight;
        InsertMinHeap(H, T);

    }

    T = DeleteMin(H);

    return T;

}