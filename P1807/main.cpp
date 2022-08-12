#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n,m,u,v,w;
struct edge{
    int u,v,w;
};
int in[1501]={0};
vector<edge> edges;
vector<int> nodes[1501];
queue<int> q;
int f[1501]={0};
int main() {
    //freopen("P1807_5.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        edges.push_back(edge{u,v,w});
        nodes[u].push_back(edges.size()-1);
        in[v]++;
    }
    for(int i=1;i<=n;++i){
        f[i]=-2e9;
        if(in[i]==0){
            q.push(i);
        }
    }
    f[1]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<nodes[now].size();++i){
            int ns=edges[nodes[now][i]].v;
            int nw=edges[nodes[now][i]].w;
            in[ns]--;
            f[ns]=max(f[ns],f[now]+nw);
            if(in[ns]==0){
                q.push(ns);
            }
        }
    }
    if(f[n]==-2e9){
        cout<<-1;
        return 0;
    }
    cout<<f[n];
    return 0;
}
