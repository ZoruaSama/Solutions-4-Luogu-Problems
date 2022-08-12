#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=3e3+10;
const int maxm=3e3+10;
int n,m;
int head[maxn],tot;
struct e{
    int to,next,w;
}E[maxm];
int s[maxm];
int f[maxn][maxm];
int ssum;
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
int dfs(int x){
    if(x>n-m){
        f[x][1]=s[x];
        f[x][0]=0;
        return 1;
    }
    int cnt=0;
    f[x][0]=0;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        int w=E[i].w;
        int t=dfs(y);
        cnt+=t;
        for(int j=cnt;j>0;--j){
            for(int k=0;k<=min(j,t);++k){
                f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]-w);
            }
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            f[i][j]=-2e9;
        }
    }
    for(int i=1;i<=n-m;++i){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            int a,c;
            scanf("%d%d",&a,&c);
            addEdge(i,a,c);
        }
    }
    for(int i=n-m+1;i<=n;++i){
        scanf("%d",s+i);
    }
    dfs(1);
    for(int i=m;i>=0;--i){
        if(f[1][i]>=0){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
