#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int mod = 1e9+7;
int t;
ll l,r;
int a[20];
int f[200][200];

int dfs(int p,int sum,int limit){
    if(p<0) return sum; //到了最后一位直接返回sum
    if(!limit && f[p][sum]>0) return f[p][sum];
    int up=limit ? a[p] : 9; //约束条件判断
    int res=0;
    for(int i=0;i<=up;++i){
        res=(res+dfs(p-1,sum+i,limit && i==up)) % mod;
    }
    if(!limit) f[p][sum]=res%mod;
    return res%mod;
}
ll solve(ll x){
    int tot=0;
    while(x!=0){
        a[tot++]=x%10;
        x/=10;
    }
    return dfs(tot-1,0,true) % mod;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",(solve(r)-solve(l-1)+mod)%mod);
    }
    return 0;
}
