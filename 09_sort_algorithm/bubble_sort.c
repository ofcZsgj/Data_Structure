#include <stdio.h>

typedef int ElementType;
void BubbleSort(ElementType array[], int Len){

    ElementType tmp;
    int i, j, flag;

    for(i = Len - 1; i > 0; --i){

        flag = 0;
        for(j = 0; j < i; ++j){

            if(array[j] > array[j + 1]){
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = 1;
            }

        }

        if(flag == 0){
            break;
        }

    }

}