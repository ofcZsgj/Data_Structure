#include <stdio.h>
typedef int ElementType;

void Insertion_Sort(ElementType A[], int N){
    ElementType tmp;
    int i, j;
    for(i = 1; i < N; ++i){
        tmp = A[i];
        for(j = i; j > 0 && A[j-1] > tmp; --j){
            A[j] = A[j-1];
        }
        A[j] = tmp;
    }
}

void Swap(ElementType* A, ElementType* B){
    ElementType tmp;
    tmp = *A;
    *A = *B;
    *B = tmp;
} 

ElementType Median3(ElementType A[], int left, int right){

    int center = ((left + right) / 2);
    if(A[left] > A[center]){
        Swap(&A[left], &A[center]); 
    }
    if(A[left] > A[right]){
        Swap(&A[left], &A[right]);
    }
    if(A[center] > A[right]){
        Swap(&A[center], &A[right]);
    }

    Swap(&A[center], &A[right-1]);

    return A[right-1];

}

void QuickSort(ElementType A[], int left, int right){

    ElementType pivot;
    int low, high, Cutoff = 2;

    if( (right - left) >= Cutoff) {

        pivot = Median3(A, left, right);
        low = left;
        high = right - 1;
        
        while(1){

            while(A[++low] < pivot);
            while(A[--high] > pivot);

            if(low < high){
                Swap(&A[low], &A[high]);
            } 
            else break;

        }
        
        Swap(&A[low], &A[right-1]);

        QuickSort(A, left, low-1);
        QuickSort(A, low+1, right);
    }
    else Insertion_Sort(A+left, right-left+1);
   
}
void Quick_Sort(ElementType A[], int N){
    QuickSort(A, 0, N-1);
}

int main(){
    int a[] = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6}, i;
    Quick_Sort(a, sizeof(a)/sizeof(int));
    for(i = 0; i < sizeof(a)/sizeof(int); ++i){
        printf("%d ", a[i]);
    }
    return 0;
}