#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct edge{
    int v,w;
};
vector<edge> nodes[2501];
vector<edge> visnodes;
bool vis[2501]={false};
int len[2501];
int n,m,s,t;
bool cmp(edge a,edge b){
    return a.w>b.w;
}
int main() {
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;++i){
        len[i]=2e9;
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        nodes[u].push_back(edge{v,w});
        nodes[v].push_back(edge{u,w});
    }
    len[s]=0;
    vis[s]=true;

    int now=s;
    while(now!=t){
        for(int i=0;i<nodes[now].size();++i){
            if(vis[nodes[now][i].v]) continue;
            len[nodes[now][i].v]=min(len[nodes[now][i].v],len[now]+nodes[now][i].w);
            visnodes.push_back(edge{nodes[now][i].v,len[nodes[now][i].v]});
        }
        sort(visnodes.begin(),visnodes.end(),cmp);
        now = visnodes[visnodes.size()-1].v;
        visnodes.pop_back();
        vis[now]=true;
    }
    cout<<len[t];
    return 0;
}
