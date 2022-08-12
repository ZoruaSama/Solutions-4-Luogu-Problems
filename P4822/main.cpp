#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxm=1e3+10;
const int maxk=100+10;
int tot;
int head[maxn*maxk];
struct e{
    int to,w,next;
}E[maxm*maxk*2];
int n,m,k;
int d[maxn*maxk];
priority_queue<pair<int,int> > q;
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
int trans(int x,int layer){
    //把点x转换为其他层级的点
    return x+(layer-1)*n;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    k++;//k次跨越 那么有k+1层。
    for(int i=1;i<=n*k;++i){
        d[i]=2e9;
    }
    for(int i=1;i<=m;++i) {
        int a, b, time;
        scanf("%d%d%d", &a, &b, &time);
        for (int l = 1; l <= k; ++l) { //同层加边
            addEdge(trans(a, l), trans(b, l), time);
            addEdge(trans(b, l), trans(a, l), time);
        }
        for (int l = 1; l < k; ++l) { //不同层加边
            addEdge(trans(a, l), trans(b, l + 1), time / 2);
            addEdge(trans(b, l), trans(a, l + 1), time / 2);
        }
    }
    d[1]=0;
    q.push(make_pair(-d[1],1));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            int w=E[i].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push(make_pair(-d[v],v));
            }
        }
    }
    int ans=2e9;
    for(int i=1;i<=k;++i){
        ans=min(ans,d[trans(n,i)]);
    }
    printf("%d",ans);
    return 0;
}
