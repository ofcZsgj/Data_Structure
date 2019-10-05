#include <stdio.h>

typedef int ElementType;
void InsertionSort(ElementType array[], int Len){

    int i, j;
    ElementType tmp;

    for(i = 1; i < Len; ++i){

        tmp = array[i];

        for(j = i; j > 0 && array[j-1] > tmp; --j){
            array[j] = array[j-1];
        }

        array[j] = tmp;

    }

}