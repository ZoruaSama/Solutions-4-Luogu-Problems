#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=5e5+10;
int n,m;
int tot;
int head[maxn];
int dep[maxn];
int f[maxn][30];
struct e{
    int to,next;
}E[maxn<<1];
int lowbit(int x){
    return log2(x&-x);
}
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void dfs(int x,int fa,int d){
    dep[x]=d;
    f[x][0]=fa;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y!=fa){
            dfs(y,x,d+1);
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]){
        return lca(y,x);
    }
    while(dep[x]>dep[y]){
        x=f[x][lowbit(dep[x]-dep[y])];
    }
    if(x==y){
        return x;
    }else{
        for(int i=(int)log2(dep[x]);i>=0;--i){
            if(f[x][i]!=f[y][i]){
                x=f[x][i];
                y=f[y][i];
            }
        }
        return f[x][0];
    }
}
int dis(int xy,int yz,int xz,int x,int y,int z){
    return dep[x]+dep[y]+dep[z]-dep[xy]-dep[yz]-dep[xz];
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n-1;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        addEdge(a,b);
        addEdge(b,a);
    }
    dfs(1,1,0);
    for(int i=1;i<30;++i){
        for(int j=1;j<=maxn;++j){
            f[j][i]=f[f[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int xy=lca(x,y);
        int yz=lca(y,z);
        int xz=lca(x,z);
        int resi=xy^yz^xz;
        int resm=dis(xy,yz,xz,x,y,z);
        printf("%d %d\n",resi,resm);
    }
    return 0;
}
