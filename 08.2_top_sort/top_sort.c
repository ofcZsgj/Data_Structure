#include <stdio.h>
#include "list_graph.h"
#include "queue.h"

#define ERROR 0
#define SUCCESS 1

int TopSort(LGraph Graph, Vertex TopOrder[]){

    Queue Q;
    Vertex V;
    PtrToAdjVNode W;
    int Indegree[Graph->Nv], i, j, cnt;

    Q = CreateQueue(Graph->Nv);

    for(V = 0; V < Graph->Nv; ++V){
        Indegree[V] = 0;
    }

    for(V = 0; V < Graph->Nv; ++V){
        for(W = Graph->L[V].FirstEdge; W; W = W->next){
            ++Indegree[W->AdjV];
        }
    }

    for(V = 0; V < Graph->Nv; ++V){
        if(Indegree[V] == 0){
            Enqueue(Q, V);
        }
    }

    cnt = 0;
    while( !IsEmpty(Q) ){

        V = Dequeue(Q);
        TopOrder[cnt++] = V;

        for(W = Graph->L[V].FirstEdge; W; W = W->next){
            if(--Indegree[W->AdjV] == 0){
                Enqueue(Q, W->AdjV);
            }          
        }

    }

    if(cnt != Graph->Nv){
        return ERROR;
    }
    else return SUCCESS;

}