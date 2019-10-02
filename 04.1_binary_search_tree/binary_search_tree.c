#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct TreeNode;
typedef struct TreeNode* Postion; 
typedef Postion BinarySearchTree;

struct TreeNode{
    ElementType data;
    BinarySearchTree left;
    BinarySearchTree right;
};

Postion Recusion_Find(BinarySearchTree BST, ElementType data){

    if(!BST){
        return NULL;
    }
    if(data > BST->data){
        return Recusion_Find(BST->right, data);
    }
    else if(data < BST->data){
        return Recusion_Find(BST->left, data);
    } 
    else return BST;

}

Postion Non_Recusion_Find(BinarySearchTree BST, ElementType data){

    while(BST){

        if(data > BST->data){
            BST = BST->right;
        }
        else if(data < BST->data){
            BST = BST->left;
        }
        else return BST;

    }

    return NULL;

}

Postion FindMax(BinarySearchTree BST){//tail recusion

    if(!BST){
        return NULL;
    }
    else if(!BST->right){
        return BST;
    }
    else return FindMax(BST->right);

}

Postion FindMin(BinarySearchTree BST){//non recusion

    if(!BST){
        return NULL;
    }

    while(BST->right){
        BST = BST->right;
    }

    return BST;

}

Postion Insert(BinarySearchTree BST, ElementType data){

    if(!BST){
        BinarySearchTree T = (BinarySearchTree)malloc(sizeof(BinarySearchTree));
        T->left = NULL;
        T->right = NULL;
        T->data = data;
    }  
    else if(data > BST->data){
        BST = Insert(BST->right, data);
    }
    else if(data < BST->data){
        BST = Insert(BST->left, data);
    }

    return BST;

}

Postion Delete(BinarySearchTree BST, ElementType data){

    if(!BST){
        return NULL;
    }

    if(data > BST->data){
        BST = Delete(BST->right, data);
    }
    else if(data < BST->data){
        BST = Delete(BST->left, data);
    }
    else{
        
        BinarySearchTree temp;
        if(BST->left && BST->right){
            temp = FindMin(BST->right);
            BST->data = temp->data;
            BST->right = Delete(BST->right, BST->data);
        }
        
        else 
        {
            Postion temp = BST;
            if(!BST->left){
                BST = BST->right;
            }
            else if(!BST->right){
                BST = BST->left;
            }
            free(temp);
        }
    }

    return BST;

}