#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=1e3+10;
int n,m;
int x[maxn],y[maxn],vis[maxn];
double d[maxn];
short mp[maxn][maxn];
double dist(int u,int v){
    if(mp[u][v]==1){
        return 0;
    }
    return sqrt((double)(x[u]-x[v])*(x[u]-x[v])+(double)(y[u]-y[v])*(y[u]-y[v]));
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&x[i],&y[i]);
        d[i]=2e9;
    }
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        mp[u][v]=mp[v][u]=1;
    }
    vis[1]=1;
    int k=1;
    double ans=0;
    for(int i=1;i<n;++i){
        int mini=0;
        double mind=2e9;
        for(int j=1;j<=n;++j){
            double w = dist(k,j);
            if(d[j] > w){
                d[j] = w;
            }
            if(mind>d[j] && !vis[j]){
                mini=j;
                mind=d[j];
            }
        }
        if(mini!=0){
            vis[mini]=1;
            ans+=mind;
            k=mini;
        }
    }
    printf("%.2lf",ans);
    return 0;
}