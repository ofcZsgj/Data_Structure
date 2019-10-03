#include <stdio.h>
#include <stdlib.h>
#include "list_graph.h"

#define true 1
#define false 0
#define MaxVertexNum 99

int Visited[MaxVertexNum] = {0};

void Visit(Vertex V){
    printf("Visit Vertex %d\n", V);
}

void DepthFirstSearch(LGraph Graph, Vertex V, void(*Visit)(Vertex)){

    PtrToAdjVNode W;

    Visit(V);
    Visited[V] = true;

    for(W = Graph->L[V].FirstEdge; W; W = W->next){

        if(!Visited[W->AdjV]){
            DepthFirstSearch(Graph, W->AdjV, Visit);        
        }

    }

}

void ListConponets(LGraph Graph){

    PtrToAdjVNode W;
    int i;
   
    for(i = 0; i < Graph->Nv; ++i){

        W = Graph->L[i].FirstEdge;
        if(!Visited[W->AdjV]){
            DepthFirstSearch(Graph, W->AdjV, Visit);
        }

    }

}
