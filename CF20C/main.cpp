#include <iostream>
#include <queue>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int maxm=1e5+10;
int n,m;
struct e{
    int to,next;
    ll w;
}E[maxm<<1];
int tot,head[maxn];
ll f[maxn];
int p[maxn];
priority_queue<pair<ll,int> >q;
void addEdge(int u,int v,ll w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
void prt(int x){
    if(p[x]!=0){
        prt(p[x]);
    }
    cout<<x<<' ';
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    for(int i=1;i<=n;++i){
        f[i]=2e18;
    }
    f[1]=0;
    q.push(make_pair(-f[1],1));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            ll w=E[i].w;
            if(f[v]>f[u]+w){
                f[v]=f[u]+w;
                p[v]=u;
                q.push(make_pair(-f[v],v));
            }
        }
    }
    if(f[n]==2e18){
        cout<<-1;
        return 0;
    }
    prt(n);
    return 0;
}
