#include <stdio.h>

int Max3(int A, int B, int C){
    return A > B ? A > C ? A : C : B > C ? B : C;
}

//Divide & Conquer
int DivideAndConquer(int a[], int left, int right){

    if(left == right){
        if(a[left] > 0){
            return a[left];
        }
        else return 0;
    }

    int center = 0, maxLeftSub = 0, maxRightSub = 0;
    int maxLeftBorderSub = 0, maxRightBorderSub = 0, leftBorderSub = 0, rightBorderSub = 0;

    center = (left + right) / 2;
    maxLeftSub = DivideAndConquer(a, left, center);
    maxRightSub = DivideAndConquer(a, center + 1, right);

    int i;
    for(i = center; i >= left; --i){
        leftBorderSub += a[i];
        if(leftBorderSub > maxLeftBorderSub){
            maxLeftBorderSub = leftBorderSub;
        }
    }

    for(i = center + 1; i <= right; ++i){
        rightBorderSub += a[i];
        if(rightBorderSub > maxRightBorderSub){
            maxRightBorderSub = rightBorderSub;
        }
    }

    return Max3(maxLeftSub, maxRightSub, (maxLeftBorderSub + maxRightBorderSub));

}

int MaxSubSeqSum(int a[], int len){
        
    return DivideAndConquer(a, 0, len - 1);

}

int main(){

    int a[] = {1, -6, 5, -2, -1, 4, 3, -5};
    int ret = MaxSubSeqSum(a, 8);
    
    printf("MaxSubSeqSum = %d\n", ret);
    return 0;

}