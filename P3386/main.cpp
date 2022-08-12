#include <iostream>
#include <cstdio>
const int maxn=510;
using namespace std;
int head[maxn];
int tot;
struct e{
    int to,next;
}E[maxn*maxn];
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int n,m,e;
int ans;
int vis[maxn];
int mt[maxn];
bool dfs(int u){ //dfs找增广路径
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(!mt[v] || dfs(mt[v])){
            //如果这个点i还未匹配则pos和他匹配，
            // 如果这个点已经匹配，那么如果本来和他匹配的点match[i]还能找到另一个点匹配则pos把i“抢”过来，
            // 让match[i]去匹配另一个点，否则就不干涉i和match[i]匹配
            mt[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d%d%d",&n,&m,&e);
    for(int i=1;i<=e;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            vis[j]=0;
        }
        if(dfs(i)) ans++;
    }
    printf("%d",ans);
    return 0;
}
