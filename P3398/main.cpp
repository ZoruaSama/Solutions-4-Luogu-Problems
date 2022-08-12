#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=1e5+10;
const int maxq=1e5+10;
int n,q;
int tot;
int head[maxn];
int f[maxn][64];
int de[maxn];
struct e{
    int to,next;
}E[maxn*2];
int lowbit(int x){
    return log2(x&-x);
}
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void dfs(int x,int fa,int dep){
    de[x]=dep;
    f[x][0]=fa;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y!=fa){
            dfs(y,x,dep+1);
        }
    }
}
int lca(int x,int y){
    if(de[x]<de[y]){
        return lca(y,x);
    }
    while(de[x]!=de[y]){
        x=f[x][lowbit(de[x]-de[y])];
    }
    if(x==y){
        return x;
    }else{
        for(int i=log2(de[x]);i>=0;--i){
            if(f[x][i]!=f[y][i]){
                x=f[x][i];
                y=f[y][i];
            }
        }
        return f[x][0];
    }
}
int dis(int x,int y){
    int z=lca(x,y);
    return abs(de[z]-de[x])+abs(de[z]-de[y]);
}
int pd(int a,int b,int c,int d){
    int ab=lca(a,b),cd=lca(c,d);
    bool ab_= (dis(a,b)==dis(a,cd)+dis(b,cd));
    bool cd_= (dis(c,d)==dis(c,ab)+dis(d,ab));
    return ab_||cd_;
}
int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,1,0);
    for(int i=1;i<64;++i){
        for(int j=1;j<=n;++j){
            f[j][i]=f[f[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=q;++i){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%c\n",(pd(a,b,c,d)?'Y':'N'));
    }
    return 0;
}
