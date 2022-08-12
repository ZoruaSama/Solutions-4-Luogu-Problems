#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=110;
int n,m;
struct e{
    int to,next;
}E[maxn*maxn];
int tot;
int head[maxn];
int match[maxn];
int vis[maxn];
int ans;
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int dfs(int u){
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v] || dfs(match[v])){
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
int main() {
    scanf("%d%d",&m,&n);
    while(true){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==-1 && v==-1) break;
        addEdge(u,v);
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            vis[j]=0;
        }
        ans+=dfs(i);
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;++i){
        if(match[i]) printf("%d %d\n",match[i],i);
    }
    return 0;
}
