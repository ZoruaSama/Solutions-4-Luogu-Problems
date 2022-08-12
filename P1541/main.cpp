#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=351;
const int maxm=121;
int n,m;
int a[maxn],b[maxm];
int memo[maxm][maxm][maxm][maxm];
int p[5];
int dfs(int x){
    if(x>n){
        return 0;
    }
    if(memo[p[1]][p[2]][p[3]][p[4]]!=0){
        return memo[p[1]][p[2]][p[3]][p[4]];
    }
    int res=0;
    for(int i=1;i<=4;++i){
        if(p[i]>0){
            p[i]--;
            res=max(res,dfs(x+i));
            p[i]++;
        }
    }
    return memo[p[1]][p[2]][p[3]][p[4]]=res+a[x];
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    for(int i=1;i<=m;++i){
        scanf("%d",b+i);
        p[b[i]]++;
    }
    printf("%d",dfs(1));
    return 0;
}
