#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int m,n,k,t;
const int maxn=5e2+10;
const int maxm=3e3+10;
struct e{
    int to,next;
    int w;
}E[maxm<<1];
int tot,head[maxn];
int dis[maxn];
int vis[maxn];
int cnt[maxn];
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].w=w;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
bool spfa(int x){
    queue<int> q;
    for(int i=1;i<=n+1;++i){
        dis[i]=2e9;
        vis[i]=0;
        cnt[i]=0;
    }
    dis[x]=1;
    vis[x]=1;
    cnt[x]++;
    q.push(x);
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            int w=E[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    cnt[v]++;
                    vis[v]=1;
                    q.push(v);
                    if(cnt[v]==n+1) return true;
                }
            }
        }
    }
    return false;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;++i){
            addEdge(n+1,i,0);
        }
        for(int i=1;i<=m;++i){
            int u,v,p;
            scanf("%d%d%d",&u,&v,&p);
            addEdge(u,v,p);
            addEdge(v,u,p);
        }
        for(int i=1;i<=k;++i){
            int u,v,p;
            scanf("%d%d%d",&u,&v,&p);
            addEdge(u,v,-p);
        }
        printf("%s\n",spfa(n+1) ? "YES":"NO");
        tot=0;
        for(int i=1;i<=n+1;++i){
            head[i]=0;
        }
    }
    return 0;
}
