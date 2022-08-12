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
void dijkstra(int s){
    for(int i=1;i<=n;++i){
        f[i]=2e18;
    }
    f[s]=0;
    q.push(make_pair(-f[s],s));
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
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int c,s,t,u,v,e;
        cin>>c;
        if(c==0){
            cin>>s>>t;
            dijkstra(s);
            if(f[t]!=2e18){
                cout<<f[t]<<endl;
            }else{
                cout<<-1<<endl;
            }

        }else{
            cin>>u>>v>>e;
            addEdge(u,v,e);
            addEdge(v,u,e);
        }
    }
    return 0;
}