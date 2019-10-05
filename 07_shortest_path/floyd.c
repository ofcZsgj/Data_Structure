#include <stdio.h>
#include "matrix_graph.h"

#define ERROR 0
#define SUCCESS 1

int Floyd(MGraph Graph, WeightType dist[][MaxVertexNum], int pre[][MaxVertexNum]){

    Vertex i, j, k;

    for(i = 0; i < Graph->Nv; ++i){
        for(j = 0; j < Graph->Nv; ++j){
            dist[i][j] = Graph->G[i][j];
            pre[i][j] = -1;
        }
    }

    for(k = 0; k < Graph->Nv; ++k){
        for(i = 0; i < Graph->Nv; ++i){
            for(j = 0; j < Graph->Nv; ++j){
                
                if( dist[i][j] > (dist[i][k] + dist[k][j]) ){

                    if( (i == j) && (Graph->G[i][j] < 0) ){
                        return ERROR;
                    }

                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }  
        }
    }
    
    return SUCCESS;

}

int main(){

    MGraph Graph;
    int VertexNum = 9;
    int dist[VertexNum][VertexNum], pre[VertexNum][VertexNum];
    
    Graph = BuildGraph();

    Floyd(Graph, dist, pre);

}
