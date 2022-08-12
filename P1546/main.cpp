#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1e3+10;
int par[maxn];
struct e{
    int u,v,w;
}E[maxn*maxn];
int tot;
int n;
int find(int x_){
    return par[x_] == x_ ? x_ : par[x_]=find(par[x_]);
}
bool cmp(e &a,e &b){
    return a.w<b.w;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int w;
            cin>>w;
            if(w!=0&&j>i){
                ++tot;
                E[tot].u=i;
                E[tot].v=j;
                E[tot].w=w;
            }
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
            ans+=E[i].w;
            if(cnt==n-1){
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}