#include <stdio.h>
#include <stdlib.h>

typedef struct LNode* PtrToLNode;
typedef PtrToLNode LGraph;
typedef struct VNode* AdjList;
typedef struct AdjVNode* PtrToAdjVNode;
typedef struct ENode* Edge;
typedef int Vertex;
typedef int WeightType;

struct AdjVNode{
    Vertex AdjV;
    WeightType Wight;
    PtrToAdjVNode next;
};

struct VNode{
    PtrToAdjVNode FirstEdge;
};

struct ENode{
    Vertex V1, V2;
    WeightType Weight;
};

struct LNode{
    int Nv;
    int Ne;
    //linked list array
    AdjList L;
};

LGraph CreateGraph(int VertexNum){

    int i;
    LGraph Graph;
    
    Graph = (LGraph)malloc(sizeof(struct LNode));
    Graph->L = (AdjList)malloc(sizeof(AdjList) * VertexNum);
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(i = 0; i < VertexNum; ++i){
        Graph->L[i].FirstEdge = NULL;
    }

    return Graph;

}

void InsertEdge(LGraph Graph, Edge Edge){

    PtrToAdjVNode new1, new2;
    
    /* <V1,V2> */
    new1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    new1->AdjV = Edge->V2;
    new1->Wight = Edge->Weight;

    new1->next = Graph->L[Edge->V1].FirstEdge;
    Graph->L[Edge->V1].FirstEdge = new1;

    /* <V2,V1> */
    new2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    new2->AdjV = Edge->V2;
    new2->Wight = Edge->Weight;

    new2->next = Graph->L[Edge->V2].FirstEdge;
    Graph->L[Edge->V2].FirstEdge = new2;

}

LGraph BuildGraph(){

    LGraph Graph;
    Edge E;
    Vertex V1, V2;
    WeightType Weight;
    int nv, i;

    scanf("%d", &nv);
    Graph = CreateGraph(nv);

    scanf("%d", &Graph->Ne);
    for(i = 0; i < Graph->Ne; ++i){

        E = (Edge)malloc(sizeof(struct ENode));
        scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);

        InsertEdge(Graph, E);

    }

    return Graph;

}