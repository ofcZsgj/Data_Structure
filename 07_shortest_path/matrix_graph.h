#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 99
#define INFINITY 9999

typedef int WeightType;
typedef int Vertex;
typedef struct GNode* PtrToGNode;
typedef PtrToGNode MGraph;
typedef struct ENode* PtrToENode;
typedef PtrToENode Edge;

struct GNode{
    int Nv;//vertex
    int Ne;//edge
    WeightType G[MaxVertexNum][MaxVertexNum];
    //DataType Data[MaxVertexNum];
};

struct ENode{
    Vertex V1, V2;
    WeightType Weight;
};

MGraph CreateGraph(int VertexNum){

    MGraph Graph = (MGraph)malloc(sizeof(MGraph));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(Vertex V; V < Graph->Nv; ++V){
        for(Vertex W; W < Graph->Nv; ++W){
            Graph->G[V][W] = INFINITY;
        }
    }

    return Graph;

}

void InsertEdge(MGraph Graph, Edge Edge){

    /* <V1,V2> */
    Graph->G[Edge->V1][Edge->V2] = Edge->Weight;
    /* <V2,V1> */
    Graph->G[Edge->V2][Edge->V1] = Edge->Weight;

}

MGraph BuildGraph(){

    MGraph Graph;
    Edge E;
    int nv, i;

    scanf("%d", &nv);
    Graph = CreateGraph(nv);
    
    scanf("%d", &Graph->Ne);
    for(i = 0; i < Graph->Ne; ++i){

        E = (Edge)malloc(sizeof(Edge));
        scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
    
        InsertEdge(Graph, E);
    
    }

    return Graph;

}













