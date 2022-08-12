#include <iostream>
#include <algorithm>
using namespace std;
int par[101];
int sum=0;
int res=0;
struct host{
    int x;
    int y;
    int m;
}hosts[101];
bool cmp(host a,host b){
    return a.m < b.m;
}
int find(int x){
    return x==par[x] ? x: par[x]=find(par[x]);
}
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=k;++i){
        int x,y,m;
        cin>>x>>y>>m;
        hosts[i].x=x;
        hosts[i].y=y;
        hosts[i].m=m;
        sum+=m;
    }
    sort(hosts+1,hosts+1+k,cmp);
    int cnt=0;
    for(int i=1;i<=k;++i){
        if(find(hosts[i].x) != find(hosts[i].y)){
            par[find(hosts[i].x)]=find(hosts[i].y);
            res+=hosts[i].m;
            cnt++;
            if(cnt==n-1){
                break;
            }
        }
    }
    cout<<sum-res;
    return 0;
}
