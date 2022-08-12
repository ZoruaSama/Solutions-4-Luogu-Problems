#include <iostream>
#include <algorithm>
using namespace std;
int par[2001];
int find(int x){
    return x==par[x]? x : par[x]=find(par[x]);
}
struct road{
    int x,y,p;
}roads[10001];
bool cmp(road a,road b){
    return a.p<b.p;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=m;++i){
        cin>>roads[i].x>>roads[i].y>>roads[i].p;
    }
    sort(roads+1,roads+1+m,cmp);
    int res=0;
    for(int i=1;i<=m;++i){
        if(find(roads[i].x)!=find(roads[i].y)){
            par[find(roads[i].x)] = find(roads[i].y);
            res = roads[i].p;
        }
    }
    cout<<res;
    return 0;
}
