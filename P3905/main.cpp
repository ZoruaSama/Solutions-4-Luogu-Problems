#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct road{
    int v;
    int k;
    bool operator<(const road x)const{
        return k>x.k;
    }
};
int f[101]={0};
bool vis[101]={false};
bool b[101][101]={false};
vector<road> nodes[101];
priority_queue<road> visn;
int main() {
    int n,m,d;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        f[i]=2e9;
    }
    for(int i=1;i<=m;++i){
        int u,v,k;
        cin>>u>>v>>k;
        nodes[u].push_back(road{v,k});
        nodes[v].push_back(road{u,k});
    }
    cin>>d;
    for(int i=1;i<=d;++i){
        int x,y;
        cin>>x>>y;
        b[x][y]=b[y][x]=true;
    }
    int s,t;
    cin>>s>>t;
    f[s]=0;
    visn.push(road{s,0});
    while(!visn.empty()){
        int now = visn.top().v; visn.pop();
        if(vis[now]) continue;
        vis[now]=true;
        for(int i=0;i<nodes[now].size();++i){
            int kkk = (b[now][nodes[now][i].v] ? nodes[now][i].k : 0);
            if(kkk + f[now] < f[nodes[now][i].v]){
                f[nodes[now][i].v] = kkk + f[now];
                visn.push(road{nodes[now][i].v,f[nodes[now][i].v]});
            }
        }
    }
    cout<<f[t];
    return 0;
}
