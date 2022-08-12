#include <iostream>
#include <vector>

using namespace std;
int t,n,m,k;
struct edge{
    int u,v,w;
};
vector<edge> edges;
int f[2001];
int plus_(int a,int b){
    if(a==2e9 || b==2e9) return 2e9;
    return a+b;
}
int main() {
    //freopen("P3385_9.in","r",stdin);
    cin>>t;
    while(t--){
        k=0;
        edges.clear();
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            f[i]=2e9;
        }
        f[1]=0;
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            if(w>=0){
                edges.push_back(edge{u,v,w});
                edges.push_back(edge{v,u,w});
            }else{
                edges.push_back(edge{u,v,w});
            }
        }
        bool flag;
        for(int i=1;i<n;++i){ //松弛i-1次
            flag=true;
            for(int j=0;j<edges.size();++j){ //松弛每一条边
                if(plus_(f[edges[j].u] , edges[j].w) < f[edges[j].v]){
                    f[edges[j].v] = plus_(f[edges[j].u] , edges[j].w);
                    flag=false;
                }
            }
            if(flag) break;
        }
        bool ans=false;
        for(int j=0;j<edges.size();++j){ //松弛每一条边
            if(plus_(f[edges[j].u] , edges[j].w) < f[edges[j].v]){
                 ans=true;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
