#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=1e5+10;
int n,m,q;

struct e{
    int to,next;
}E[maxn<<1];
int tot,head[maxn];
int dis[maxn][2];

void addEdge(int u,int v){
    tot++;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void dijkstra(){
    for(int i=1;i<=n;++i){
        dis[i][0]=2e9;
        dis[i][1]=2e9;
    }
    dis[1][0]=0;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(-dis[1][0],1));
    while(!q.empty()){
        int u = q.top().second;q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v = E[i].to;
            if(dis[u][0]+1<dis[v][1]){
                dis[v][1]=dis[u][0]+1;
                q.push(make_pair(-dis[v][1],v));
            }
            if(dis[u][1]+1<dis[v][0]){
                dis[v][0]=dis[u][1]+1;
                q.push(make_pair(-dis[v][0],v));
            }
        }
    }
}
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dijkstra();
    for(int i=1;i<=q;++i){
        int a,L;
        scanf("%d%d",&a,&L);
        if(L>=dis[a][L%2]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}