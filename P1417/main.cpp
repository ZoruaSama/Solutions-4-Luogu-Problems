#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn=51;
const int maxt=1e6+10;
int T,n;
struct e{
    int a,b,c;
}E[maxn];
ll f[maxt];
bool cmp(e &x,e &y){
    return x.b * y.c > x.c * y.b;
}
int main() {
    scanf("%d%d",&T,&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&E[i].a);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&E[i].b);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&E[i].c);
    }
    sort(E+1,E+1+n,cmp);
    for(int i=1;i<=n;++i){
        for(int j=T;j>=E[i].c;--j){
            f[j]=max(f[j],f[j-E[i].c]+E[i].a-(ll)j*E[i].b);
        }
    }
    ll ans=0;
    for(int i=1;i<=T;++i){
        ans=max(ans,f[i]);
    }
    printf("%lld",ans);
    return 0;
}
