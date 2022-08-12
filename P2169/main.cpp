#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 2e5+10;
const int maxm = 1e6+10;
int n,m;
struct e{
    int to,w,next;
}E[maxm],E_[maxm];
int tot,tot_;
int head[maxn],head_[maxn];
int t;
int dfn[maxn],low[maxn],vis[maxn],color[maxn];
int colorcnt;
int f[maxn];
int vis_[maxn];
stack<int> s;
priority_queue<pair<int,int> >q;
void addLine(int u,int v,int w){
    E[++tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
void addLine_(int u,int v,int w){
    E_[++tot_].to=v;
    E_[tot_].w=w;
    E_[tot_].next=head_[u];
    head_[u]=tot_;
}

void tarjan(int x){
    dfn[x]=low[x]=++t;
    vis[x]=1;
    s.push(x);
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(vis[y]){
            low[x]=min(low[x],low[y]);
        }
    }
    if(dfn[x]==low[x]){
        colorcnt++;
        while(s.top()!=x){
            vis[s.top()]=0;
            color[s.top()]=colorcnt;
            s.pop();
        }
        vis[s.top()]=0;
        color[s.top()]=colorcnt;
        s.pop();
    }
}
int main() {
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        addLine(u,v,w);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=head[i];j;j=E[j].next){
            int y=E[j].to;
            if(color[i]!=color[y]){
                addLine_(color[i],color[y],E[j].w);
            }
        }
    }
    for(int i=1;i<=colorcnt;++i){
        f[i]=2e9;
    }
    f[color[1]]=0;
    q.push(make_pair(0,color[1]));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis_[u]) continue;
        vis_[u]=1;
        for(int j=head_[u];j;j=E_[j].next){
            int v=E_[j].to;
            int w=E_[j].w;
            if(f[v]>f[u]+w){
                f[v]=f[u]+w;
                q.push(make_pair(-f[v],v));
            }
        }
    }
    cout<<f[color[n]];
    return 0;
}
