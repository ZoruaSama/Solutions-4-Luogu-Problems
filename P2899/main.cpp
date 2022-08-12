#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e4+10;
int n;
struct e{
    int to,next;
}E[maxn<<1];
int tot,head[maxn];
int f[maxn][3];

//f[i][0]表示i被自己覆盖 的最小花费
//f[i][1]表示i被儿子覆盖 的最小花费
//f[i][2]表示i被父亲覆盖 的最小花费
int min3(int a,int b,int c){
    return min(a,min(b,c));
}
void dfs(int u,int fa){
    f[u][0]=1;
    f[u][1]=0;
    f[u][2]=0;
    int sp=0;int minsp=2e9;
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(v!=fa){
            dfs(v,u);
            f[u][0]+=min3(f[v][0],f[v][1],f[v][2]);
            f[u][2]+=min(f[v][0],f[v][1]);
//            if(minsp>f[v][0]){
//                sp=v;
//                minsp=f[v][0];
//            }
            if(f[sp][0]-min(f[sp][0],f[sp][1]) > f[v][0]-min(f[v][0],f[v][1])){
                sp=v;
            }
        }
    }
    f[u][1]=f[sp][0];
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].to;
        if(v!=fa && v!=sp){
            f[u][1]+=min(f[v][0],f[v][1]);
        }
    }
}
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int main() {
    scanf("%d",&n);
    f[0][0]=2e9; //woc???
    for(int i=1;i<=n-1;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        addEdge(a,b);
        addEdge(b,a);
    }
    dfs(1,-1);
    printf("%d",min(f[1][0],f[1][1]));
    return 0;
}
