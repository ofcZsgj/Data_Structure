#include <stdio.h>
#include "queue.h"
#include "list_graph.h"

void Unweighted(LGraph Graph, Vertex S, int dist[], int pre[]){

    PtrToAdjVNode W;
    Vertex V;
    Queue Q;

    Q = CreateQueue(Graph->Nv);
    dist[S] = 0;
    Enqueue(Q, S);
    
    while( !IsEmpty(Q) ){
        
        V = Dequeue(Q);
        for(W = Graph->L[V].FirstEdge; W; W = W->next){
            
            if(dist[W->AdjV] == -1){

                dist[W->AdjV] = dist[V] + 1;
                pre[W->AdjV] = V;
                Enqueue(Q, W->AdjV);

            }

        }

    }

}

int main(){

    LGraph Graph;
    Edge E;
    int i, VertexNum = 9;
    int dist[VertexNum], pre[VertexNum];
    
    Graph = CreateGraph(VertexNum);

    for(i = 0; i < VertexNum; ++i){
        dist[i] = -1;
        pre[i] = -1;
    }

    Unweighted(Graph, 3, dist, pre);

    return 0;

}