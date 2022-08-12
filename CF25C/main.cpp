#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn=310;
int n,k;
ll d[maxn][maxn];
ll ans;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%lld",&d[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ans+=d[i][j];
        }
    }
    scanf("%d",&k);
    while(k--){
        int a,b;
        ll c;
        scanf("%d%d%lld",&a,&b,&c);
        if(d[a][b]<=c){
            printf("%lld ",ans>>1);
            continue;
        }
        d[b][a]=d[a][b]=c;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
               if(i!=j){
                   d[j][i]=d[i][j]=min(d[i][j],d[i][a]+d[a][j]);
                   d[j][i]=d[i][j]=min(d[i][j],d[i][b]+d[b][j]);
               }
            }
        }
        ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                ans+=d[i][j];
            }
        }
        printf("%lld ",ans>>1);
    }
    return 0;
}
