#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
#define N 20
#define M 20
#define W 20
struct itemstruct {
    //char name[20];
    int top; //取前三还是前五
    int score[5];
    int range[5];
    int inum;
};
struct athletestruct {
    char name[20];
    int score;
    int range;
};
struct school {
    int snum;
    int menscore;
    int womenscore;
    int totalscore;
    struct itemstruct item[M+W];
    struct athletestruct athlete[5];
};

struct school a[N];

void input(int n,int m,int w);
void output(int n,int m,int w);
void sortput(int n,int m,int w);
void serchput(int n,int m,int w);

int main()
{
    
}

void input(int n,int m,int w)
{
    int i,j,k,s,q=0;
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i].snum);
        for(j=0; j<m+w; j++)
        {
            scanf("%d", &a[i].item[j].inum);
            scanf("%d", &a[i].item[j].top);
            scanf("%d",&k);
            for(s=0; s<k; s++)
            {
                scanf("%d", &a[i].item[j].range[s]);
            }
            printf("\n");
        }
    }
    for(i=0; i<n; i++)
    {
        a[i].totalscore=0;
        a[i].womenscore=0;
        a[i].totalscore=0;
    }
}
