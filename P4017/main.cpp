#include <iostream>
using namespace std;
#include <algorithm>
int n,m;
const int maxn=5005;
int sb[maxn],nb[maxn];
int rc[maxn]={0};
const int mod = 80112002;
int ans;
bool mp[maxn][maxn]={0};
int dfs(int x){
    int sum = 0;
    if(rc[x]!=0){
        return rc[x];
    }
    if(!nb[x]){
        return 1;
    }
    for(int i=1;i<=n;i++){
        if(mp[i][x]){
            sum += dfs(i);
            sum %= mod;
        }
    }
    return rc[x] = sum;
}
int main() {
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        sb[x]++;
        nb[y]++;
        mp[x][y]=true;
    }
    ans=0;
    for(int i=1;i<=n;i++){
        if(!sb[i]){ //食物链的顶部
            ans += dfs(i);
            ans %= mod;
        }
    }
    cout<<ans;
    return 0;
}



/*
 * 我求成最长链了……
 * int sb[maxn],nb[maxn];
const int mod = 80112002;
int ans;
bool mp[maxn][maxn]={0};
int dfs(int x){
    int sum = 1;
    if(!nb[x]){
        return sum % mod;
    }
    for(int i=1;i<=n;i++){
        if(mp[i][x]){
            sum = max(dfs(i) + 1,sum) % mod;
        }
    }
    return sum % mod;
}
int main() {
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        sb[x]++;
        nb[y]++;
        mp[x][y]=true;
    }
    ans=1;
    for(int i=1;i<=n;i++){
        if(!sb[i]){ //食物链的顶部
            ans = max(dfs(i),ans);
        }
    }
    cout<<ans;
    return 0;
}
 *
 * */