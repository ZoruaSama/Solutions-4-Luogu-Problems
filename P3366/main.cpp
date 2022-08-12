#include <iostream>
#include <algorithm>
using namespace std;
int par[5001];
int find(int x){
    return x==par[x] ? x : par[x]=find(par[x]);
}
struct edge{
    int x,y,z;
}edges[200001];
bool cmp(edge e1,edge e2){
    return e1.z<e2.z;
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        par[i]=i;
    }
    for(int i=1;i<=m;++i){
        cin>>edges[i].x>>edges[i].y>>edges[i].z;
    }
    sort(edges+1,edges+1+m,cmp);
    int cnt=0;
    int ans=0;
    for(int i=1;i<=m;++i){
        if(find(edges[i].x)!=find(edges[i].y)){
            par[find(edges[i].x)]=find(edges[i].y);
            cnt++;
            ans+=edges[i].z;
        }
    }
    if(cnt==n-1){
        cout<<ans;
    }else{
        cout<<-1;
    }
    return 0;
}
