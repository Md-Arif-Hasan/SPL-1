#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100], trans[100][100], color[100],d[100],f[100], time =0, count = 1, component[100], prev[100];

int findmax(int n){
    int i, max = -1, maxnode;
    for(i=0; i<n; i++){
        if(f[i] > max) {
            max = f[i];
            maxnode = i;
        }
    }
    f[maxnode] = -1;
    return maxnode;
}


void DFS_visit_SCC(int u, int n) {

    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(trans[u][v]==1) {
            if(color[v]==WHITE)
            {
                DFS_visit_SCC(v,n);
            }
        }
    }

    color[u]=BLACK;
    component[u] = count;
}

void DFS_SCC(int n)
{
    for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0;u<n;u++) {
        int max = findmax(n);
        if(color[max]==WHITE){
            DFS_visit_SCC(max,n);
            count++;
            }
    }
}


void DFS_visit(int u, int n) {
    time++;
    d[u]=time;
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(G[u][v]==1) {
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visit(v,n);
            }
        }
    }
    time++;
    f[u]=time;
    color[u]=BLACK;
}

void DFS(int n)
{
    for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0;u<n;u++) {
        if(color[u]==WHITE)
            DFS_visit(u,n);
    }
}

int main() {
  //  freopen("a.txt", "r", stdin);

    int n, e, u, v;
    scanf("%d" , &n);
    string name[n];
    scanf("%d",&e);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
            trans[i][j]=0;
        }
    }

    int i = 0, j = 0, flag = 0, name_counter = 0;

    for(int i=0;i<e;i++)

    {
        flag = 0;
        string x , y;
        cin >> x>> y;

        for(j = 0; j<= name_counter ; j++){
                if(name[j]==x){
                flag = 1;
                u = j;
                break;
            }
        }
        if(flag == 0){
            name[name_counter] = x;
            u = name_counter;
            name_counter++;
        }

        flag =0;

        for(j = 0; j<= name_counter ; j++){
            if(name[j]==y){

                flag = 1;
                v = j;
                break;
            }
        }
        if(flag == 0){
            name[name_counter] = y;
            v = name_counter;
            name_counter++;
        }
     //   cout << "u = " << u << "   v = " << v <<endl;
        G[u][v] = 1;
        trans[v][u] = 1;


    }
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << G[i][j] << " ";

        }
        cout << endl;
    }

    DFS(n);
    printf("\n");


    DFS_SCC(n);

    printf("\n");printf("\n");
    for(int i=1; i<count; i++){
        printf("Circle %d : ", i);
        for(int j=0; j<n; j++){
            if(component[j] == i){
                cout << name[j] << " " ;
                }
        }
        printf("\n");
    }



}











