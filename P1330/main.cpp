#include <iostream>
#include <queue>
using namespace std;
const int maxn=1e4+10;
const int maxm=1e5+10;
int n,m;
int t[maxn];
int h[maxn];
int par[maxn];
int vis[maxn];
int ans;
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
void merge(int x,int y){
    x=find(x);
    if(x!=y){
        par[y]=x;
        t[x]+=t[y];
    }
}
int main() {
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=n;++i){
        par[i]=i;
        t[i]=1;
    }
    for(int i=1;i<=m;++i){
        cin>>u>>v;
        int x1=find(u),x2=find(v);
        if(x1!=x2){
            if(h[u]) merge(h[u],x2);
            if(h[v]) merge(h[v],x1);
            h[u]=x2;
            h[v]=x1;
        }else{
            cout<<"Impossible";
            return 0;
        }
    }
    for(int i=1;i<=n;++i){
        int q=find(i);
        int p=find(h[i]);
        if(!vis[q]){
            vis[q]=vis[p]=1;
            ans+=min(t[q],t[p]);
        }
    }
    cout<<ans;
    return 0;
}