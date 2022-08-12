#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e6+10;
int n;
int w[maxn];
int head[maxn];
int tot;
struct e{
    int to,next;
}E[maxn*2];
int dep[maxn];
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }

    return 0;
}
