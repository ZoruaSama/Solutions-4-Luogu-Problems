#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=1e3+10;
int n,m;
struct e{
    int to,next,w;
}E[maxn*maxn];
int head[maxn];
int tot;
int dist[maxn];
int vis[maxn][maxn];
int par[maxn];
int ans;
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    E[tot].w=w;
    head[u]=tot;
}
void dijkstra(int s){
    priority_queue<pair<int,int> >q;
    for(int i=1;i<=n;++i){
        dist[i]=2e9;
    }
    dist[n]=0;
    q.push(make_pair(dist[n],n));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            if(vis[u][v] || vis[v][u]) continue;
            if(dist[v]>dist[u]+E[i].w){
                dist[v]=dist[u]+E[i].w;
                if(s==1) par[v]=u;
                q.push(make_pair(-dist[v],v));
            }
        }
    }
}
void prt(int x){
    if(x==0) return ;
    vis[par[x]][x]=1;
    vis[x][par[x]]=1;
    dijkstra(0);
    ans=max(ans,dist[1]);
    vis[par[x]][x]=0;
    vis[x][par[x]]=0;
    prt(par[x]);

}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    dijkstra(1);
    prt(1);
    printf("%d",ans);
    return 0;
}