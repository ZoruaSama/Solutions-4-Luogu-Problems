#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
int n,m,s,t;
double d[101];
bool vis[101];

struct node{
    double x,y;
}nodes[101];
struct edge{
    int v;
    double w;
};
struct cmp{ //仿函数
    bool operator() (int &a,int &b){
        return d[a]>d[b];
    }
};
vector<edge> edges[101];

priority_queue<int,vector<int>,cmp> q;

double dist(node &a,node &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        d[i]=2e9;
        cin>>nodes[i].x>>nodes[i].y;
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        double w=dist(nodes[x],nodes[y]);
        edges[x].push_back(edge{y,w});
        edges[y].push_back(edge{x,w});
    }
    cin>>s>>t;
    d[s]=0;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u=q.top();q.pop();
        int size = edges[u].size();
        for(int i=0;i<size;++i){
            int v=edges[u][i].v;
            double w=edges[u][i].w;
            d[v]=min(d[v],d[u]+w);
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
    printf("%.2lf",d[t]);
    return 0;
}
