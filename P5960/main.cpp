#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=5e3+10;
int n,m;
struct e{
    int to,next,w;
}E[maxn<<2];
int head[maxn];
int tot;
int dis[maxn];
bool vis[maxn];
int num[maxn];
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
bool spfa(int x){
    queue<int> q;
    dis[x]=0;
    q.push(x);
    vis[x]=true;
    num[x]++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            int w=E[i].w;
            if(dis[v] > dis[u] + w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
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
    for(int i=1;i<=n;++i){
        dis[i]=2e9;
    }
    for(int i=1;i<=m;++i){
        int c,c_,y;
        scanf("%d%d%d",&c,&c_,&y);
        addEdge(c_,c,y);
    }
    for(int i=1;i<=n;++i){
        addEdge(n+1,i,0);
    }
    if(!spfa(n+1)) printf("NO\n");
    else{
        for(int i=1;i<=n;++i){
            printf("%d ",dis[i]);
        }
    }
    return 0;
}
