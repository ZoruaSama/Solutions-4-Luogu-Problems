#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int n,m,s,t;
map<pair<int,int>,int> mp;
struct road{
    int u;
    int v;
    int w;
}roads[20010];
int par[10001];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
bool cmp(road a,road b){
    return a.w < b.w;
}
int main() {
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        roads[i].u = u;
        roads[i].v = v;
        roads[i].w = w;

//        if((mp.count(make_pair(u,v))==1 && mp[make_pair(u,v)]<w) || mp.count(make_pair(u,v))==0){
//            mp[make_pair(u,v)]=w;
//            mp[make_pair(v,u)]=w;
//        }
    }
    sort(roads+1,roads+1+m,cmp);
    int res=0;
    for(int i=1;i<=m;++i){
        if(find(roads[i].u) != find(roads[i].v)){
            par[find(roads[i].u)]=find(roads[i].v);
            res=roads[i].w;
        }
        if(find(s)==find(t)){
            break;
        }
    }
    cout<<res;
    return 0;
}
