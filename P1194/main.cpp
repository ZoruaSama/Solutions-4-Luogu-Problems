#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxa=1e3+10;
const int maxb=5e2+10;
int a,b;
int par[maxb];
int tot;
struct e{
    int u,v,w;
}E[maxb*maxb+maxb];
void addEdge(int u,int v,int w){
    ++tot;
    E[tot].u=u;
    E[tot].v=v;
    E[tot].w=w;
}
bool cmp(e &x,e &y){
    return x.w<y.w;
}
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
int main() {
    scanf("%d%d",&a,&b);
    for(int i=1;i<=b;++i) {
        par[i] = i;
        addEdge(b+1,i,a);
    }
    for(int i=1;i<=b;++i){
        for(int j=1;j<=b;++j){
            int w;
            scanf("%d",&w);
            if(w!=0){
                addEdge(i,j,w);
            }
        }
    }
    sort(E+1,E+1+tot,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=tot;++i){
        int u = find(E[i].u);
        int v = find(E[i].v);
        if(u!=v){
            par[u]=v;
            ans+=E[i].w;
            cnt++;
            if(cnt==tot-1){
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
