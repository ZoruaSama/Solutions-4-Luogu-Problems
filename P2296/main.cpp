#include <iostream>
#include <cstdio>
using namespace std;
int n,m,s,t;
const int maxn=1e4+10;
const int maxm=2e5+10;
struct e{
    int to,next;
}E[maxm];
int tot,head[maxn];

void addEdge(int u,int v){
    tot++;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        addEdge(x,y);
    }
    scanf("%d%d",&s,&t);

    return 0;
}
