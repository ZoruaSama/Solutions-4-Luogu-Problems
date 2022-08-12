#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n,m;
const int maxn=5e2+10;
int d[maxn];
int sum[maxn];
int dp[maxn][maxn];
//前i个村庄中建立j个小学的最小距离总和
int f[maxn][maxn];
//从第i个村庄到第j个村庄 [i,j]只建一座小学的最小距离总和
int dist(int x,int y){
    return abs(sum[y]-sum[x]);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n-1;++i){
        scanf("%d",&d[i]);
        sum[i+1]=sum[i]+d[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int mid=(i+j)>>1;
            for(int k=i;k<=j;++k){
                f[i][j]+=dist(k,mid);
            }
        }
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            dp[i][j]=2e9;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(j>i){
                dp[i][j]=0;
                continue;
            }
            for(int k=j-1;k<=i;++k){
                dp[i][j]=min(dp[i][j],dp[k][j-1]+f[k+1][i]);
            }
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}
