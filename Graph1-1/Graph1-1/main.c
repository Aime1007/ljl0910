
#include <stdio.h>
#include <stdlib.h>
typedef struct GNode * PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    int G[100][100];
    int Data[100];
};
typedef PtrToGNode MGraph;
typedef struct ENode * PtrToENode;
struct ENode {
    int v1,v2;
    int Weight;
};
typedef PtrToENode Edge;

MGraph Create(int VNum)
{
    int V,W;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VNum;
    Graph->Ne=0;
    for (V=0; V<Graph->Nv; V++) {
        for (W=0; W<Graph->Nv; W++) {
            Graph->G[V][W]=0;
        }
    }
    return Graph;
}

void Insert(MGraph Graph, Edge E)
{
    Graph->G[E->v1][E->v2]=E->Weight;
}

MGraph Build()
{
    MGraph Graph;
    int V;
    Edge E;
    int Nv;
    scanf("%d", &Nv);
    Graph=Create(Nv);
    scanf("%d", &(Graph->Ne));
    if(Graph->Ne!=0) {
        E=(Edge)malloc(sizeof(struct ENode));
        for(int i=0; i<Graph->Ne; i++) {
            scanf("%d %d %d", &E->v1, &E->v2, &E->Weight);
            Insert(Graph, E);
        }
    }
    for (V=0; V<Graph->Nv; V++) {
        scanf("%d", &(Graph->Data[V]));
    }
    return Graph;
}
int main(int argc, const char * argv[]) {
    MGraph Graph;
    Graph=Build();
    return 0;
}
