#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
const int maxn=5e2+10;
const int maxp=8e2+10;
const int maxc=15e2+10;
int n,p,c;
int num[maxp];
struct e_{
    int to,next,w;
}E[maxc<<1];
int tot;
int head[maxp];
int ans=2e9;
int f[maxp];
void addEdge(int u,int v,int d){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    E[tot].w=d;
    head[u]=tot;
}
void dijkstra(int x){
    priority_queue<pair<int,int> >q;
    for(int i=1;i<=p;++i){
        f[i]=2e9;
    }
    f[x]=0;
    q.push(make_pair(-f[x],x));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            int w=E[i].w;
            if(f[v]>f[u]+w){
                f[v]=f[u]+w;
                q.push(make_pair(-f[v],v));
            }
        }
    }
}
int main() {
    scanf("%d%d%d",&n,&p,&c);
    for(int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        num[a]++;
    }
    for(int i=1;i<=c;++i){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        addEdge(a,b,d);
        addEdge(b,a,d);
    }
    for(int i=1;i<=p;++i){
        dijkstra(i);
        int sum=0;
        for(int j=1;j<=p;++j){
            sum+=num[j]*f[j];
        }
        ans=min(ans,sum);
    }
    printf("%d",ans);
    return 0;
}
