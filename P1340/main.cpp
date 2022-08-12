#include <iostream>
#include <cstdio>
const int maxn = 2e2+10;
const int maxw = 6e3+10;
int n,w;
int par[maxn];
int head[maxn];
int tot;
struct e{
    int to,next,w;
}E[maxn<<1];
void addEdge(int u,int v,int r){
    ++tot;
    E[tot].to=v;
    E[tot].w=r;
    E[tot].next=head[u];
    head[u]=tot;
}
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
int main() {
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=w;++i){
        int u,v,r;
        scanf("%d%d%d",&u,&v,&r);
        addEdge(u,v,r);
        if(find(u)!=find(v)){

        }
    }
    return 0;
}
