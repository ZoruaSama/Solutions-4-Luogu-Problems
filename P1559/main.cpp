#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=21;
int n;
int p[maxn][maxn];
int q[maxn][maxn];
int select[maxn];
int s[maxn];
int ans;
void dfs(int x,int sum){
    if(x>n){
        ans=max(ans,sum);
        return ;
    }
    if(sum+(s[n]-s[x-1])<=ans){
        return ;
    }
    for(int i=1;i<=n;++i){
        if(!select[i]){
            select[i]=1;
            dfs(x+1,sum+p[x][i]*q[i][x]);
            select[i]=0;
        }
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&p[i][j]);
        }
    }
    for(int i=1;i<=n;++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &q[i][j]);
        }
    }
    for(int i=1;i<=n;++i) {
        int tmp=0;
        for (int j = 1; j <= n; ++j) {
            tmp=max(tmp,p[i][j]*q[j][i]);
        }
        s[i]=tmp;
    }
    for(int i=1;i<=n;++i){
        s[i]+=s[i-1];
    }
    dfs(1,0);
    printf("%d",ans);
    return 0;
}
