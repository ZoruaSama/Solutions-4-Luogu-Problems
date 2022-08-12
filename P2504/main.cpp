#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1e3+10;
const int maxm=5e2+10;
int par[maxn];
struct e{
    int u,v;
    double w;
}E[maxn*maxn];
int dis[maxm];
int x[maxn],y[maxn];
int tot;
int n,m;
int find(int x_){
    return par[x_] == x_ ? x_ : par[x_]=find(par[x_]);
}
bool cmp(e &a,e &b){
    return a.w<b.w;
}
int main() {
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>dis[i];
    }
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
        par[i]=i;
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            E[++tot].u=i;
            E[tot].v=j;
            E[tot].w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    sort(E+1,E+1+tot,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=tot;++i){
        int u=find(E[i].u);
        int v=find(E[i].v);
        if(u!=v){
            cnt++;
            par[u]=v;
            if(cnt==n-1){
                for(int j=1;j<=m;++j){
                    if(E[i].w<=dis[j]){
                        ans++;
                    }
                }
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
