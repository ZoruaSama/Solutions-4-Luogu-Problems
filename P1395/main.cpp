#include <iostream>
using namespace std;
const int maxn=5e4+10;
struct e{
    int to,next;
}E[maxn*2];
int head[maxn];
int tot;
int n;
int size[maxn];
int f[maxn];
int ans=2e9;
int ans_=2e9;
void addEdge(int u,int v){
    if(u==0 || v==0) return;
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void dfs(int x,int fa,int dep){
    size[x]=1;
    for(int i=head[x];i;i=E[i].next){
        int y = E[i].to;
        if(y!=fa){
            dfs(y,x,dep+1);
            size[x]+=size[y];
        }
    }
    f[1]+=dep;
}
void dp(int x,int fa){
    for(int i=head[x];i;i=E[i].next){
        int y = E[i].to;
        if( y != fa){
            f[y] = f[x] + size[1] - size[y]*2;
            dp(y,x);
        }
        if(ans>f[y]){
            ans=f[y];
            ans_=y;
        }else if(ans==f[y] && ans_ > y){
            ans_=y;
        }
    }
}
int main() {
    int a,b;
    cin>>n;
    for(int i=1;i<=n-1;++i){
        cin>>a>>b;
        addEdge(a,b);
        addEdge(b,a);
    }
    dfs(1,0,0);
    dp(1,0);
    cout<<ans_<<' '<<ans;
    return 0;
}
