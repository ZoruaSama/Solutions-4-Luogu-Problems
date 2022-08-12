#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
const int maxm=25;
int n,m;
int a[maxn];
int s[maxn][maxm]; //前i个人中属于j组的人数
int num[maxm]; //i组的人数
//int order[maxm];//组别的顺序 用于形成全排列
int f[1<<maxm];
int len[1<<maxm];

int dfs(int status){
    if(f[status] != 2e9){
        return f[status]; //记忆化搜索
    }
    for(int i=1;i<=m;++i){
        if(status & (1<<(i-1))){ //如果这个状态下第i组已经排完
            int l = len[status] - num[i] + 1; //确定这一组的范围
            int r = len[status];
            int w = num[i]-(s[r][i]-s[l-1][i]); //要出列的人数
            f[status] = min(f[status],dfs(status ^ (1<<(i-1))) + w);
        }
    }
    return f[status];
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        num[a[i]]++;
        s[i][a[i]]++;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            s[i][j] += s[i-1][j];
        }
    }//处理成前缀和
    int maxs=(1<<m)-1;
    for(int i=1;i<=maxs;++i){
        f[i]=2e9;
    }
    for(int i=1;i<=maxs;++i){  //遍历每一种状态
        for(int j=1;j<=m;++j){ //遍历这个状态的每一个组
            if(i&(1<<(j-1))){  //如果这个状态下这个组已经完成
                len[i]+=num[j]; //这个状态下已经完成的组的长度
            }
        }
    }
    printf("%d",dfs(maxs));
    return 0;
}