#include <stdio.h>
#include "stack.h"

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int visit;//record visit number
};
typedef struct TreeNode* BinaryTree;

void InOrderTraversal(BinaryTree BT){

    BinaryTree T = BT;
    Stack S = CreateStack();

    while(T || IsEmpty(S)){

        while(T){
            push(S, T);
            T = T->left;
        }
    
        if(!IsEmpty(S)){
            T = Pop(S);
            printf(" %d ", T->data);
            T = T->right;
        }

    }

}

void PostOrderTraversal(BinaryTree BT){

    BinaryTree T = BT;
    T->visit = 0;

    Stack S = CreateStack();

    while(T || IsEmpty(S)){

        while(T){
            if(T->visit == 0){
                ++T->visit;
                push(S, T);
            }
            T = T->left;
        }
    
        if(!IsEmpty(S)){

            T = Pop(S);
            if(T->visit == 2){
                printf(" %d ", T->data);
                T = NULL;//avoid unlimited circulate
            }

            else{
                ++T->visit;
                push(S, T);
                T = T->right;
            }

        }

    }

}

void PreOrderTraversal(BinaryTree BT){

    BinaryTree T = BT;
    Stack S = CreateStack();

    while(T || IsEmpty(S)){

        while(T){
            printf(" %d ", T->data);
            push(S, T);
            T = T->left;
        }
    
        if(!IsEmpty(S)){
            T = Pop(S);          
            T = T->right;
        }

    }

}