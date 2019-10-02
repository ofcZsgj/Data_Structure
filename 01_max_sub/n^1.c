#include <stdio.h>

//online treat
int MaxSubSeqSum(int a[], int len){

    int maxSub = 0, thisSub = 0;

    for(int i = 0; i < len; ++i){

        thisSub += a[i];

        if(thisSub > maxSub){
            maxSub = thisSub;
        }        
        else if(thisSub < 0){
            thisSub = 0;
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