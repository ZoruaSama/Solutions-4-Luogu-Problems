#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
const int maxn=8e4+10;
const int maxm=2e5+10;
int n,m,s;
int tot,tot_;
int head[maxn];
int head_[maxn];
struct e{
    int to,w,next;
    double f;
}E[maxm],E_[maxm];
int dfn[maxn],low[maxn],vis[maxn];
int t;
stack<int> S;
int color[maxn];
int colorcnt;
int colorw[maxn];
int dis[maxn];
int in[maxn];
int calw(int w,double f){
    if(w==0) return 0;
    return w+calw((int)(w*f),f);
}
void addLine(int u,int v,int w,double f){
    E[++tot].to=v;
    E[tot].w=w;
    E[tot].f=f;
    E[tot].next=head[u];
    head[u]=tot;
}
void addLine_(int u,int v,int w,double f){
    E_[++tot_].to=v;
    E_[tot_].w=w;
    E_[tot_].f=f;
    E_[tot_].next=head_[u];
    head_[u]=tot_;
}
void tarjan(int x){
    dfn[x]=low[x]=++t;
    vis[x]=1;
    S.push(x);
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(dfn[y]==0){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(vis[y]==1){
            low[x]=min(low[x],low[y]);
        }
    }
    if(dfn[x]==low[x]){
        ++colorcnt;
        while(S.top()!=x){
            color[S.top()]=colorcnt;
            vis[S.top()]=0;
            S.pop();
        }
        color[S.top()]=colorcnt;
        vis[S.top()]=0;
        S.pop();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    //cin>>n>>m;
    double f;
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d%lf",&u,&v,&w,&f);
        //cin>>u>>v>>w>>f;
        addLine(u,v,w,f);
    }
    scanf("%d",&s);
    for(int i=1;i<=n;++i){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    for(int u=1;u<=n;++u){
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            int w=E[i].w;
            if(color[u]!=color[v]){
                addLine_(color[u],color[v],w,f);
                in[color[v]]++;
            }else{
                int colorid=color[v];
                colorw[colorid]+=calw(E[i].w, E[i].f);
            }
        }
    }
    queue<int> q;
    for(int i=1;i<=colorcnt;++i){
        dis[i]=-2e9;
        if(in[i]==0){
            q.push(i);
        }
    }
    dis[color[s]]=colorw[color[s]];
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i=head_[u];i;i=E_[i].next){
            int v = E_[i].to;
            int w = E_[i].w;
            dis[v]=max(dis[v], dis[u] + w + colorw[v]);
            in[v]--;
            if(in[v]==0){
                q.push(v);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=colorcnt;++i){
        ans=max(ans,dis[i]);
    }
    cout<<ans;
    return 0;
}
