#include <stdio.h>

typedef int ElementType;
void ShellSort(ElementType array[], int Len){

    ElementType tmp;
    int S, D, P, i;
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for(S = 0; Sedgewick[S] >= Len; ++S){
        ;
    }

    for(D = Sedgewick[S]; D > 0; D = Sedgewick[++S]){

        for(P = D; P < Len; ++P){

            tmp = array[P];
            for(i = P; i >= D && array[i-D] > tmp; i -= D){
                array[i] = array[i-D];
            }
            array[i] = tmp;

        }

    }


}