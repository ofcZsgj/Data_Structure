#include <stdio.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode* BinaryTree;

void PreOrderTraversal(BinaryTree BT){

    if(BT){
        printf("%d ", BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }

}

void InOrderTraversal(BinaryTree BT){

    if(BT){
        PreOrderTraversal(BT->left);
        printf("%d ", BT->data);
        PreOrderTraversal(BT->right);
    }

}

void PostOrderTraversal(BinaryTree BT){

    if(BT){
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
        printf("%d ", BT->data);
    }

}