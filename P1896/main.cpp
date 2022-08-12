#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn=15;
int n,k;
int numsf[1<<maxn];
ll f[maxn][1<<maxn][maxn*maxn];
ll ans;
int p[maxn][1<<maxn];//有k个王的状态序列
int tot[maxn];
int nums(int x){
    int count = 0;
    while (x != 0) {
        ++count;
        x = (x - 1) & x;
    }
    return count;

}
ll dfs(int state,int line,int king){
    if(king<0) return 0;//原来是少了个这个才TLE的…… 沃日
    if(f[line][state][king]!=0) return f[line][state][king];
    if(line>n){
        return king==0;
    }
    ll res=0;
    for(int kk=0;kk<=min(king,n);++kk){
        for(int j=1;j<=tot[kk];++j){
            int i=p[kk][j];
            if((i&state)==0 && (i & (i>>1)) == 0 && (i&(state<<1))==0 && (i&(state>>1))==0){
                res+=dfs(i,line+1,king-numsf[i]);
            }
        }
    }
    return f[line][state][king] = res;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<=((1<<n)-1);++i){
        numsf[i]=nums(i);
    }
    for(int i=0;i<=((1<<n)-1);++i){
        if((i & (i>>1))==0){
            p[numsf[i]][++tot[numsf[i]]] = i;
        }
    }
    dfs(0,1,k);
    for(int i=0;i<=((1<<n)-1);++i){
        ans+=f[1][i][k];
    }
    printf("%lld",ans);
    return 0;
}
