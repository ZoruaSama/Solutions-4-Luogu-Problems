#include <iostream>
#include <cstdio>
using namespace std;
const int maxh=6e4+10;
const int maxn=110;
int h,n;
int p[maxn],c[maxn];
int f[maxh];
int main() {
    scanf("%d%d",&n,&h);
    for(int i=1;i<=h+5000;++i){
        f[i]=2e9;
    }
    for(int i=1;i<=n;++i){
        scanf("%d%d",p+i,c+i);
    }
    for(int i=1;i<=n;++i){
        for(int j=p[i];j<=h+5000;++j){
            f[j]=min(f[j],f[j-p[i]]+c[i]);
        }
    }
    int ans=2e9;
    for(int i=h;i<=h+5000;++i){
        ans=min(ans,f[i]);
    }
    printf("%d",ans);
    return 0;
}
