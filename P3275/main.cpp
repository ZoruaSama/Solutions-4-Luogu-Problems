#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=1e6+10;
int n,m;
struct e{
    int to,next,w;
}E[maxn];
int head[maxn],tot;
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
int dis[maxn];
int vis[maxn];
int num[maxn];
bool spfa(int x){
    queue<int> q;
    for(int i=1;i<=n;++i){
        dis[i]=2e9;
    }
    dis[x]=0;
    q.push(x);
    vis[x]=true;
    num[x]++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            int w=E[i].w;
            if(dis[v] > dis[u] + w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    num[v]++;
                    if(num[v]==n) return false;
                }
            }
        }
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int t,a,b,c;
        scanf("%d",&t);
        if(t==1) {
            scanf("%d%d%d",&a,&b,&c);
            //a-b>=c;
            //a>=b+c;
            addEdge(a,b,-c);

        }else if(t==2){
            scanf("%d%d%d",&a,&b,&c);
            //a-b<=c;
            //b>=a-c;
            addEdge(b,a,c);
        }else{
            scanf("%d%d",&a,&b);
            addEdge(a,b,0);
            addEdge(b,a,0);
        }
    }
    for(int i=1;i<=n;++i){
        addEdge(n+1,i,0);
    }
    printf("%s",spfa(n+1)?"Yes":"No");
    return 0;
}