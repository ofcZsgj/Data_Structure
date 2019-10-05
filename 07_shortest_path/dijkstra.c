#include <stdio.h>
#include "matrix_graph.h"

#define true 1
#define false 0
#define ERROR -1

Vertex FindMinDist(MGraph Graph, int dist[], int Collected[]){

    Vertex V, MinV;
    int MinDist = INFINITY;

    for(V = 0; V < Graph->Nv; ++V){

        if( (dist[V] < MinDist) && (Collected[V] == true) ){
            MinDist = dist[V];
            MinV = V;
        }

    }

    if (MinV < INFINITY){
        return MinV;
    }
    else return ERROR;

}

int Dijkstra(MGraph Graph, Vertex S, int dist[], int pre[]){

    Vertex V, W;
    int Collected[Graph->Nv];

    for(V = 0; V < Graph->Nv; ++V){
        
        Collected[V] = false;
        dist[V] = Graph->G[S][V];

        if(dist[V] < INFINITY){
            pre[V] = S;
        }

    }

    Collected[S]= true;
    dist[S] = 0;

    while(1){

        V = FindMinDist(Graph, dist, Collected);
        if(V == ERROR){
            break;
        }

        Collected[V] = true;

        for(W = 0; W; ++W){
            
            if( (Collected[W] == false) && (Graph->G[V][W] < INFINITY) ){
                
                if(Graph->G[V][W] < 0){
                    return false;
                }

                if( (dist[W] > (dist[V] + Graph->G[V][W])) ){
                    dist[W] = (dist[V] + Graph->G[V][W]); 
                    pre[W] = V;
                }

            }
            
        }

    }

    return true;

}

int main(){

    MGraph Graph;
    int i, dist[7], pre[7];

    Graph = CreateGraph(7);
    
    /* insert edge */

    for(i = 0; i < 7; ++i){
        dist[i] = INFINITY;
        pre[i] = -1;
    }

    Dijkstra(Graph, 1, dist, pre);

    return 0;

}