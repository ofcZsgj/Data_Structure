#include <stdio.h>
#include "list_graph.h"
#include "queue.h"
#define true 1
#define false 0

int Visited[MaxVertexNum] = {0};

void Visit(Vertex V){
    printf("Visit Vertex %d\n", V);
}

void BreadthFirstSearch(LGraph Graph, Vertex V, void(*Visit)(Vertex)){

    Queue Q;
    PtrToAdjVNode W;

    Q = CreateQueue(MaxVertexNum);

    Visit(V);
    Visited[V] = true;
    Enqueue(Q, Graph->L[V].FirstEdge);

    while(IsEmpty(Q) || W){

        W = Dequeue(Q);
        for(; W; W = W->next){

            if(!Visited[W->AdjV]){

                Visit(W->AdjV);
                Visited[W->AdjV] = true;
                Enqueue(Q, W);

            }

        }

    }

}
