#include <iostream>
using namespace std;
const int maxn = 1e4+10;
const int maxm = 5e3+10;
int n,m,w;
struct p{
    int c,d;
    bool vis;
}P[maxn];
int par[maxn];
int f[maxn];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
void merge(int x,int y){
    if(x>y){
        merge(y,x);
        return ;
    }else{
        par[find(x)]=find(y);
    }
}
int main() {
    cin>>n>>m>>w;
    for(int i=1;i<=n;++i){
        par[i]=i;
        cin>>P[i].c>>P[i].d;
        P[i].vis=false;
    }
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        P[u].vis=false;
        P[v].vis=false;
        merge(u,v);
    }
    for(int i=1;i<=n;++i){
        if(par[i]!=i){
            P[par[i]].c+=P[i].c;
            P[par[i]].d+=P[i].d;
        }else{
            P[i].vis=true;
        }
    }
    for(int i=1;i<=n;++i){
        if(P[i].vis){
            for(int j=w;j>=P[i].c;--j){
                f[j]=max(f[j],f[j-P[i].c]+P[i].d);
            }
        }
    }
    cout<<f[w];
    return 0;
}
