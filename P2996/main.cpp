#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=5e4+10;
struct e{
    int to,next;
}E[maxn<<1];
int n;
int head[maxn],tot;
int f[maxn][2]; //以i为根结点 是/否访问i结点的情况
void dfs(int u,int fa){
    f[u][0]=0;
    f[u][1]=1;
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(v!=fa){
            dfs(v,u);
            f[u][0]+=max(f[v][0],f[v][1]);
            f[u][1]+=f[v][0];
        }
    }
}
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        int c1,c2;
        scanf("%d%d",&c1,&c2);
        addEdge(c1,c2);
        addEdge(c2,c1);
    }
    dfs(1,1);
    printf("%d",max(f[1][0],f[1][1]));
    return 0;
}
