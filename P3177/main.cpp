#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e6+10;
int n,k;

int head[maxn];
int tot;
struct e{
    int to,next;
}E[maxn*2];
int f[maxn][2];
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }

    return 0;
}
