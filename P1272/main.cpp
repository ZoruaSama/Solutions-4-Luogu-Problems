#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=150+10;
int n,p;
int tot;
int in[maxn];
int head[maxn];
struct e{
    int to,next;
}E[maxn];
int f[maxn][maxn];
// 以i为根结点的树 保留j个节点要砍掉的最少的边数
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
    in[u]++;
    in[v]++;
}
void dfs(int x){
    f[x][1]=min(f[x][1],in[x]);
    for(int u=head[x];u;u=E[u].next){
        int y=E[u].to;
        dfs(y);
        for(int i=p;i>=1;--i){
            for(int j=1;j<i;++j){
                f[x][i]=min(f[x][i],f[x][j]+f[y][i-j]-2);
            }
        }
    }
}
int main() {
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            f[i][j]=maxn;
        }
    }
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
    }
    dfs(1);
    int ans=maxn;
    for(int i=1;i<=n;++i){
        ans=min(ans,f[i][p]);
    }
    printf("%d",ans);
    return 0;
}
