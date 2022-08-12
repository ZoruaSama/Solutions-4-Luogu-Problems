#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn=5e6+10;
int n;
struct e{
    int to,next;
}E[maxn<<1];
int tot,head[maxn];
ll ans;
int par[maxn];
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
ll dfs(int u,int fa){
    ll d1=0,d2=0;
    ll dist=0;
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(v!=fa){
            ll d = dfs(v,u)+1;
            dist = max(dist,d);
            if(d>d1) d2=d1,d1=d;
            else if(d>d2) d2=d;
        }
    }
    ans=max(ans,d1+d2);
    return dist;
}
void dfs_(int u,int fa){
    par[u]=fa;
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(v!=fa){
            dfs_(v,u);
        }
    }
}
int node(int a,int b){
    return (a-1)*n+b;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        for(int j=1;j<=n;++j){
            addEdge(node(j,u),node(j,v));
            addEdge(node(j,v),node(j,u));
        }
    }
    dfs_(1,1);
    for(int i=2;i<=n;++i){
        addEdge(node(i,1),node(par[i],par[i]));
        addEdge(node(par[i],par[i]),node(i,1));
    }
    dfs(1,1);
    printf("%lld",ans+1);
    return 0;
}
