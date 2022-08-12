#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=25;
const int maxa=105;
int n,m;
int a[maxn];
int flag[maxn];
bool f[maxn*maxa];
int res;
//从n个数字里选取m个数字删除
void dp(int tot){ //进行这个情况下的背包dp
    int ans=0;
    for(int j=0;j<maxn*maxa;++j){
        f[j]=false;
    }
    f[0]=true;
    for(int i=1;i<=n;++i){
        if(flag[i]) continue;
        for(int j=tot;j>=0;--j){
            if(f[j]&&!f[j+a[i]]){
                f[j+a[i]]=true;
                ans++;
            }
        }
    }
    res=max(ans,res);
}
void dfs(int x,int y,int sum){ //先枚举再DP
    // x: 选取的第几个
    // y: 已经放弃的砝码数
    if(y>m) return ;
    if(x>n){
        if(y==m){
            dp(sum);
        }
        return ;
    }
    dfs(x+1,y,sum+a[x]); //不放弃
    flag[x]=1;
    dfs(x+1,y+1,sum); //放弃
    flag[x]=0;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    dfs(1,0,0);
    printf("%d",res);
    return 0;
}


/*
#include <bitset>
#include <cstdio>
int w[25];
int table[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
int popcount(unsigned int x) { // 返回x的二进制中1的个数
    int ret = 0;
    for(int i = 0; i < 8; i++) ret += table[x & 15], x >>= 4;
    return ret;
}
int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", w + i);
    for(int i = 0, li = 1 << n; i < li; i++) {
        if(popcount(i) == n - m) {
            std::bitset<2010> S;
            S[0] = 1;
            for(int j = 0; j < n; j++) if(i & (1 << j)) S |= S << w[j];
            int siz = S.count();
            ans = ans > siz ? ans : siz;
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}
 */