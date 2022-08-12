#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a,b;
const int N=20;
int num[N];
int f[N][N];//f[i][j]表示一共有i位，最高位数字为j的windy数的个数
int dfs(int p,int last,bool limit,bool leading0){
    if(p<0){
        return 1;
    }
    if(!limit && !leading0 && f[p][last]>=0) {
        return f[p][last];
    }
    int up=limit?num[p]:9;
    int res=0;
    for(int i=0;i<=up;++i){
        if(leading0 || abs(i-last)>=2){
            res+=dfs(p-1,i,limit && i==up,leading0 && i==0);
        }
    }
    if(!limit && !leading0) return f[p][last] = res;
    return res;
}
int solve(int x){
    int tot=0;
    while(x){
        num[tot++]=x%10;
        x/=10;
    }
    return dfs(tot-1,0,true,true);
}
int main() {
    scanf("%d%d",&a,&b);
    for(int i=0;i<=15;++i){
        for(int j=0;j<=15;++j){
            f[i][j]=-1;
        }
    }
    printf("%d\n",solve(b)-solve(a-1));
    return 0;
}
