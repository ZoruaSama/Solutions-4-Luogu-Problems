#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e4+10;
const int maxm=2e3+10;
int n,m,k;
int x[maxn];
int y[maxn];
int l[maxn];
int h[maxn];
int vis[maxn];
int f[maxn][maxm];//横坐标为i时 纵坐标为j时 最少点击次数
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<=n-1;++i){
        scanf("%d%d",x+i, y+i);
    }
    for(int i=0;i<=n;++i){
        l[i]=0;h[i]=m+1;
    }
    for(int i=1;i<=k;++i){
        int p;
        scanf("%d",&p);
        scanf("%d%d",l+p,h+p);
        vis[p]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<=m;++j){
            f[i][j]=2e9;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=x[i-1]+1;j<=m+x[i-1];++j){
            //原地蹦跶的状态转移
            f[i][j]=min(f[i-1][j-x[i-1]]+1,f[i][j-x[i-1]]+1);
        }
        for(int j=m+1;j<=m+x[i-1];++j){
            //在顶上蹦跶的状态转移
            f[i][m]=min(f[i][j],f[i][m]);
        }
        for(int j=1;j<=m-y[i-1];++j){
            //dio落的状态转移
            f[i][j]=min(f[i][j],f[i-1][j+y[i-1]]);
        }
        for(int j=1;j<=l[i];++j){
            //不能经过的地方重新修正
            f[i][j]=2e9;
        }
        for(int j=h[i];j<=m;++j){
            //不能经过的地方重新修正
            f[i][j]=2e9;
        }
    }
    int ans=2e9;
    for(int i=1;i<=m;++i){
        ans=min(ans,f[n][i]);
    }
    if(ans<2e9){
        printf("%d\n%d",1,ans);
    }else{
        int i,j;
        for(i=n;i>=1;--i){
            for(j=1;j<=m;++j){
                if(f[i][j]<2e9) break;
            }
            if(j<=m) break; //若: 上面的循环是非正常结束的
        }
        ans=0;
        for(j=1;j<=i;++j){
            ans+=vis[j];
        }
        printf("%d\n%d",0,ans);
    }
    return 0;
}
