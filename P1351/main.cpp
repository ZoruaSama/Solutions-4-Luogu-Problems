#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
const int maxn=2e5+10;
const int mod=1e4+7;
struct e{
    int to,next;
}E[maxn<<1];
int tot,head[maxn];
int w[maxn];
int ans,sum;
int tmp1,tmp2;
int max1,max2;

void addEdge(int u,int v){
    tot++;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",w+i);
    }
    for(int u=1;u<=n;++u){
        tmp1=tmp2=max1=max2=0;
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            tmp1=(tmp1+w[v])%mod;
            tmp2=(tmp2+w[v]*w[v])%mod;
            if(w[v]>max1) max2=max1,max1=w[v];
            else if(w[v]>max2) max2=w[v];
        }
        sum+=(tmp1*tmp1-tmp2)%mod;
        sum%=mod;
        ans=max(ans,max1*max2);
    }
    printf("%d %d",ans,sum%mod);
    return 0;
}