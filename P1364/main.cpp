#include <iostream>
using namespace std;
const int maxn=110;
struct e{
    int to,next;
}E[maxn*2];
int head[maxn];
int tot;
void addEdge(int u,int v){
    if(u==0 || v==0) return;
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int w[maxn];
int n;
int ans=2e9;
int f[maxn],size[maxn];
void dfs(int x,int fa,int dep){
    size[x]=w[x];
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if( y != fa){
            dfs(E[i].to,x,dep+1);
            size[x]+=size[y];
        }
    }
    f[1] += w[x]*dep;
}
void dp(int x,int fa){
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if( y != fa){
            f[y] = f[x] + size[1]-size[y]*2;
            dp(y,x);
        }
        ans=min(ans,f[y]);
    }
}
int main() {
    cin>>n;
    int u,v;
    for(int i=1;i<=n;++i){
        cin>>w[i]>>u>>v;
        addEdge(i,u);
        addEdge(u,i);
        addEdge(i,v);
        addEdge(v,i);
    }
    dfs(1,0,0);
    dp(1,0);
    cout<<ans;
    return 0;
}
