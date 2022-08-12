#include <iostream>
#include <cstdio>
using namespace std;
int m,n;
const int maxn=15;
const int maxm=15;
const int mod=1e8;

int vis[1<<maxn];
int ans;
int f[maxn][1<<maxm];

//有点像八皇后的问题 = =……。

int dfs(int state,int line){
    if(f[line][state]!=0) return f[line][state];
    if(line>m){
        return 1;
    }
    int res=0;
    for(int i=0;i<=((1<<n)-1);++i){
        if((i&state)==0 && (i & vis[line])==0 && (i & (i>>1)) == 0){
            res+=dfs(i,line+1);
        }
    }
    return f[line][state] = res;

}
int main() {
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            int a;
            scanf("%d",&a);
            if(a==0){
                vis[i]|=1<<(n-j);
            }
        }
    }
    dfs(0,1);
    for(int i=0;i<=((1<<n)-1);++i){
        ans+=f[1][i];
        ans%=mod;
    }
    printf("%d",ans);
    return 0;
}
