#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=2e3+10;
int n,c;
int x[maxn],y[maxn],d[maxn],vis[maxn];
int dist(int u,int v){
    int w = (x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]);
    if(w<c){
        return 2e9;
    }else{
        return w;
    }
}
int main() {
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&x[i],&y[i]);
        d[i]=2e9;
    }
    vis[1]=1;
    int k=1;
    long long ans=0;
    int cnt=0;
    for(int i=1;i<n;++i){
        int mini=0;
        int mind=2e9;
        for(int j=1;j<=n;++j){
            int w = dist(k,j);
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
            cnt++;
            k=mini;
        }
    }
    if(cnt!=n-1){
        printf("-1");
    }else{
        printf("%lld",ans);
    }
    return 0;
}