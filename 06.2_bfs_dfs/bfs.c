#include <stdio.h>
#include "list_graph.h"
#include "queue.h"
#define true 1
#define false 0

int Visited[MaxVertexNum] = {0};

void Visit(Vertex V){
    printf("Visit Vertex %d\n", V);
}

void BreadthFirstSearch(LGraph Graph, Vertex S, void(*Visit)(Vertex)){

    Queue Q;
    Vertex V;
    PtrToAdjVNode W;

    Q = CreateQueue(Graph->Nv);

    Visit(S);
    Visited[S] = true;
    Enqueue(Q, S);

    while(IsEmpty(Q) || W){

        V = Dequeue(Q);
        for(W = Graph->L[V].FirstEdge; W; W = W->next){

            if(!Visited[W->AdjV]){

                Visit(W->AdjV);
                Visited[W->AdjV] = true;
                Enqueue(Q, W->AdjV);

            }

        }

    }

}
