#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=4e3+10;
int n;
int head[maxn];
int tot;
struct e{
    int to,next;
}E[maxn<<4];
int match[maxn][3];
int vis[maxn];
int ans;
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
bool dfs(int u){
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v][1] || dfs(match[v][1])){
            match[v][1]=u;
            return true;
        }else if(!match[v][2] || dfs(match[v][2])){
            match[v][2]=u;
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n*2;++i){
        int s1,s2;
        scanf("%d%d",&s1,&s2);
        addEdge(i,s1);
        addEdge(i,s2);
    }
    for(int i=1;i<=n*2;++i){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    printf("%d",ans);
    return 0;
}
