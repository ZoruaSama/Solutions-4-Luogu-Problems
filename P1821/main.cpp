#include <iostream>
#include <queue>
using namespace std;
const int maxn=1e3+10;
const int maxm=1e5+10;
int n,m,x;
int tot;
int tot_;
int head[maxn];
int head_[maxn];
struct e{
    int to,next,w;
}E[maxm],E_[maxm];
int f[maxn];
int g[maxn];
priority_queue<pair<int,int> > q;
void addLine(int u,int v,int w){
    E[++tot].to = v;
    E[tot].next = head[u];
    E[tot].w = w;
    head[u]=tot;
}
void addLine_(int u,int v,int w){
    E_[++tot_].to = v;
    E_[tot_].next = head_[u];
    E_[tot_].w = w;
    head_[u]=tot;
}
int main() {
    cin>>n>>m>>x;
    int u,v,w;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        addLine(v,u,w);
        addLine_(u,v,w);
    }
    for(int i=1;i<=n;++i){
        f[i]=2e9;
        g[i]=2e9;
    }
    f[x]=0;
    q.push(make_pair(0,x));
    while(!q.empty()){
        int u = q.top().second;q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v = E[i].to;
            int w = E[i].w;
            if(f[u]+w<f[v]){
                f[v]=f[u]+w;
                q.push(make_pair(-f[v],v));
            }
        }
    }
    g[x]=0;
    q.push(make_pair(0,x));
    while(!q.empty()){
        int u = q.top().second;q.pop();
        for(int i=head_[u];i;i=E_[i].next){
            int v = E_[i].to;
            int w = E_[i].w;
            if(g[u]+w<g[v]){
                g[v]=g[u]+w;
                q.push(make_pair(-g[v],v));
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,f[i]+g[i]);
    }
    cout<<ans;
    return 0;
}
