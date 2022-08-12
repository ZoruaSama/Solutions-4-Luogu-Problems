#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=1e3+10;
const int maxm=1e4+10;
int n,m;
struct e{
    int to,next,w;
}E[maxm];
int tot,head[maxm];
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
int dis[maxn];
int vis[maxn];
int num[maxn];
bool spfa(int x){
    for(int i=1;i<=n;++i){
        dis[i]=2e9;
    }
    queue<int> q;
    dis[x]=0;
    q.push(x);
    vis[x]=1;
    num[x]++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            int w=E[i].w;
            if(dis[v] > dis[u] + w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    num[v]++;
                    if(num[v]==n+1) return false;
                }
            }
        }
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int s,t,w;
        scanf("%d%d%d",&s,&t,&w);
        addEdge(s,t,-w);
    }
    if(spfa(1)){
//        for(int i=1;i<=n;++i){
//            printf("%d ",dis[i]);
//        }
        int ans=dis[n];
        if(spfa(n)){
            ans=min(ans,dis[1]);
        }else{
            printf("Forever love");
            return 0;
        }
        printf("%d",ans);
    }else{
        printf("Forever love");
    }
    return 0;
}
