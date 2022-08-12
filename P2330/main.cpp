#include <iostream>
#include <algorithm>
using namespace std;
struct road{
    int u;
    int v;
    int c;
}roads[100000];
int par[301];
bool cmp(road a,road b){
    return a.c < b.c;
}
int find(int x){
    return x==par[x]? x : par[x]=find(par[x]);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=m;++i){
        cin>>roads[i].u>>roads[i].v>>roads[i].c;
    }
    sort(roads+1,roads+1+m,cmp);
    int s=0,re=0;
    for(int i=1;i<=m;++i){
        if(find(roads[i].u)!=find(roads[i].v)){
            par[find(roads[i].u)]=find(roads[i].v);
            s++;
            re=roads[i].c;
        }
    }
    cout<<s<<' '<<re;
    return 0;
}
