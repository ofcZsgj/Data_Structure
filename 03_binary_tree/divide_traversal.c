#include <stdio.h>

int pre[] = {1, 2 ,3 ,4, 5, 6};
int in[] = {3, 2, 4, 1, 6, 5};
int post[6];

void DividePostTraversal(int preL, int inL, int postL, int N){

    if(N == 0){
        return;
    }
    else if(N == 1){
        post[postL] = pre[preL];
        return;
    }
    
    int root, i, left, right;

    root = pre[preL];
    post[postL + N -1] = root;
    
    for(i = 0; i < N; ++i){

        if(in[inL + i] == root){
            break;
        }

    }
    
    /* bus error
    for(i = inL; i < N; ++i){
        if(in[i] == root){
            break;
        }
    }
    */

    left = i;
    right = N - i - 1;

    //preL + 1 Segmentation fault : 11
    DividePostTraversal(preL + 1, inL, postL, left);
    DividePostTraversal(preL + left + 1, inL + left + 1, postL + left, right);

}

int main(){

    DividePostTraversal(0, 0, 0, 6);
    for(int i = 0; i < 6; ++i){
        printf("%d ", post[i]);
    }

    return 0;

}