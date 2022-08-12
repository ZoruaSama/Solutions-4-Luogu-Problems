#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=2e3+10;
const int maxm=1e5+10;
int head[maxn];
int tot;
struct e{
    int to,next;
    double w;
}E[maxm*2];
void addEdge(int u,int v,double w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
int n,m;
double d[maxn];
priority_queue<pair<int,int> > q;
int main() {
    //freopen("P1576_9.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        double z;
        cin>>x>>y>>z;
        z=(100-z)/100;
        addEdge(x,y,z);
        addEdge(y,x,z);
    }
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=n;++i){
        d[i]=0;
    }
    d[a]=1;
    q.push(make_pair(d[a],a));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            double w=E[i].w;
            double nw=d[u]*w;
            if(d[v]<nw){
                d[v]=nw;
                q.push(make_pair(d[v],v));
            }
        }
    }
    printf("%.8lf",100/d[b]);
    return 0;
}
