#include <iostream>
using namespace std;

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    int G[100][100];
};
typedef PtrToGNode MGraph;

typedef struct ENode *PtrToENode;
struct ENode {
    int v1,v2;
    int weight;
};
typedef PtrToENode Edge;

MGraph Create(int num)
{
    int v,w;
    MGraph Graph;
    
    Graph = new GNode;
    Graph->Nv=num;
    Graph->Ne=0;
    for(v=0; v<Graph->Nv; v++)
        for(w=0; w<Graph->Nv; w++)
            Graph->G[v][w]=65535;
    return Graph;
}

void Insert(MGraph Graph, Edge E)
{
    Graph->G[E->v1][E->v2]=E->weight;
    Graph->G[E->v2][E->v1]=E->weight;
}

MGraph Build()
{
    MGraph Graph;
    int Nv;
    Edge E;
    cin >> Nv;
    Graph=Create(Nv);
    cin >> Graph->Nv;
    if(Graph->Ne !=0) {
        E = new ENode;
        for(int i=0; i<Graph->Ne; i++) {
            cin >> E->v1 >> E->v2 >> E->weight;
            Insert(Graph, E);
        }
    }
    return Graph;
}
