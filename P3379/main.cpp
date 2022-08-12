#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn=500001;
vector<int> node[maxn];
int dep[maxn];
int f[maxn][22]; //2^20
int lowbit(int x){
    return log2(x&(-x));
}
void dfs(int u,int fa,int d){
    dep[u]=d;
    f[u][0]=fa;
    for(int i=0;i<node[u].size();++i){
        if(node[u][i]==fa) continue;
        dfs(node[u][i],u,d+1);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]){
        x=f[x][lowbit(dep[x]-dep[y])];
    }
    if(x==y) return x;// or return y.
    for(int i=log2(dep[x]);i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}
int main() {
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<n;++i){
        int x,y;
        x=read();
        y=read();
        node[x].push_back(y);
        node[y].push_back(x);
    }
    dfs(s,s,0);
    for(int i=1;i<22;++i){
        for(int u=1;u<=n;u++){
            f[u][i]=f[f[u][i-1]][i-1];
        }
    }
    for(int i=1;i<=m;++i){
        int x,y;
        x=read();
        y=read();
        cout<<lca(x,y)<<endl;
    }
    return 0;
}
