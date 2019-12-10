
#include <stdio.h>
int G[10][10],Nv,Ne;
void BuildGraph()
{
    int i,j,v1,v2,w;
    
    scanf("%d", &Nv);
    for(i=0; i<Nv; i++)
        for(j=0; j<Nv; j++)
            G[i][j] = 0;
    scanf("%d", &Ne);
    for(i=0; i<Ne; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}
int main(int argc, const char * argv[]) {
    BuildGraph();
    for (int i=0; i<Nv; i++) {
        for (int j=0; j<Nv; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}
