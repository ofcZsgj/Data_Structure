#include <stdio.h>

int MaxSubSeqSum(int a[], int len){

    int maxSub = 0, thisSub = 0;
    int i = 0, j;

    for(; i < len; ++i){//sub left
        
        thisSub = 0;
        for(j = i; j < len; ++j){//sub right
            
            thisSub += a[j];

            if(thisSub > maxSub){
                maxSub = thisSub;
            }

        }

    }

    return maxSub;

}

int main(){

    int a[] = {1, -6, 5, -2, -1, 4, 3, -5};
    int ret = MaxSubSeqSum(a, 8);
    
    printf("MaxSubSeqSum = %d\n", ret);
    return 0;

}