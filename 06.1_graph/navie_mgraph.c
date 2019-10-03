#include <stdio.h>
#define MaxVertexNum 99

int G[MaxVertexNum][MaxVertexNum];
int Nv, Ne;

void BuildGraph(){

    int i, j, v1, v2, w;

    scanf("%d", &Nv);
    for(i = 0; i < Nv; ++i){
        for(j = 0; j < Ne; ++j){
            G[i][j] = 0;
        }
    }

    scanf("%d", &Ne);
    for(i = 0; i < Ne; ++i){

        scanf("%d %d %d", &v1, &v2, &w);
        
        G[v1][v2] = w;
        G[v2][v1] = w;
    
    }

}

