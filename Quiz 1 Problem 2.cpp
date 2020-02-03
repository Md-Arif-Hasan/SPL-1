#include<stdio.h>
#include<iostream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100];
int color[100], d[100], f[100], prev[100],low[100],arra[100];
int time=0;
int top=0;
void print_path(int s, int v)
{
    if(s==v)
    {
        printf("%d->",s);
    }
    else if(prev[v]==-1)
    {
        printf("No Path");
    }
    else
    {
        print_path(s,prev[v]);
        printf("%d->",v);
    }
}

void DFS_visit(int u, int n)
{
    time++;
    d[u]=time;
    low[u]=d[u];
    color[u]=GRAY;
    for(int v=0; v<n; v++)
    {
        if(G[u][v]==1)
        {
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visit(v,n);
                if(low[v]>=d[u]){
                    arra[top++]=u;
                }
                if(low[v]<low[u])low[u]=low[v];
            }
            else if(color[v]==GRAY&&prev[u]!=v){
                if(d[v]<low[u])low[u]=low[v];
            }
        }
    }
    time++;
    f[u]=time;
    color[u]=BLACK;
}

void DFS(int n)
{
    for(int i=0; i<n; i++)
    {
        color[i]=WHITE;
        prev[i]=-1;
        low[i]=-1;
        f[i]=0;
    }
    time = 0;
    for(int u=0; u<n; u++)
    {
        if(color[u]==WHITE)
        {
            DFS_visit(u,n);
        }
    }
}

int main(){
    int n, i, j , u , v;
    while(1){



        cin >> n;
        if(n == 0) return 0;
         i = 0;
        while(i<n){
            cin >> u;
            if(u==0) break;
            int j =0;
            while(j<n){
                cin>> v;
                if(v==0) break;
                G[u-1][v-1] = 1;
                G[v-1][u-1] = 1;
                j++;
            }
            i++;

        }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }
    DFS(n);
    top=top-1;
    int ans =0;

    for(int i=0;i<top;i++){
        for(int j=0;j<top;j++)
            {
                if(i!=j && arra[i]==arra[j])
                    arra[j] = -1;

            }
    }
    for(int i = 0; i<top; i++){
        if(arra[i]!=-1)
            ans++;
    }
    cout << ans<< endl;

    }


}
