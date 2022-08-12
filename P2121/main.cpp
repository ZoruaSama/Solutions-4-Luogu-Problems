#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100001;
int par[maxn];
struct road{
    int u,v,w;
}roads[maxn];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
bool cmp(road a,road b){
    return a.w > b.w;
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        roads[i].u=u;
        roads[i].v=v;
        roads[i].w=w;
    }
    sort(roads+1,roads+1+m,cmp);
    int res=0;
    int cnt=0;
    for(int i=1;i<=m;++i){
        int x=find(roads[i].u);
        int y=find(roads[i].v);
        if(x!=y){
            par[x]=y;
            res+=roads[i].w;
            cnt++;
            if(cnt==k) break;
        }
    }
    cout<<res;
    return 0;
}
