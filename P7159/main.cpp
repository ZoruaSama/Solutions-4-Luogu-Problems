#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn=1e6+10;
const int mod=998244353;
int n;
ll a[maxn];
struct e{
    int to,next;
}E[maxn<<1];
int tot,head[maxn];
ll dep[maxn];
void addEdge(int u,int v){
    tot++;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void dfs(int u,int fa,int d){
    dep[u]=d;
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(v!=fa){
            dfs(v,u,d+1);
        }
    }
}
ll ans;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,1,1);
    for(int i=1;i<=n;++i){
        ans+=a[i]*dep[i];
        ans%=mod;
    }
    for(int i=1;i<=n-1;++i){
        ans*=2;
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}
