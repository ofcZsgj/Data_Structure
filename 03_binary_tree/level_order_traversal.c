#include <stdio.h>
#include "queue.h"

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode* BinaryTree;

void LevelOrderTraversal(BinaryTree BT){

    BinaryTree T = BT;
    Queue Q = CreateQueue(99);

    Enqueue(Q, (void**)&T);
    
    while(IsEmpty(Q)){

        T = Dequeue(Q);
        printf(" %d ", T->data);

        if(T->left){
            Enqueue(Q, (void**)T->left);
        }

        if(T->right){
            Enqueue(Q, (void**)T->right);
        }

    }

}