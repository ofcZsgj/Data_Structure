#include <stdio.h>

typedef int ElementType;

void PercDown(ElementType A[], int p, int N){

    ElementType tmp;
    int parent, child;

    tmp = A[p];
    for( parent = p; (parent * 2 + 1) < N; parent = child ){

        child = parent * 2 + 1;
        if( (child != (N - 1)) && (A[child+1] > A[child]) ){
            ++child;
        }

        if( tmp >= A[child] ){
            break;
        }
        else{
            A[parent] = A[child];
        }

    }

    A[parent] = tmp;

}

void HeapSort(ElementType A[], int N){

    int i;
    ElementType tmp;

    for( i = (N/2 -1); i >= 0; --i ){
        PercDown(A, i, N);
    }

    for( i = N-1; i > 0; --i ){
        
        tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;

        PercDown(A, 0, i);

    }

}

int main(){
    ElementType a[] = {1,2,4,65,23,99,435,23,1,1,23,53,57,85,86,34,54,0,21,64};
    HeapSort(a, sizeof(a)/sizeof(int));
    for(int i = 0; i < sizeof(a)/sizeof(int); ++i){
        printf("%d ", a[i]);
    }
    return 0;
}