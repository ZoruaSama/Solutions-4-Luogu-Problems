#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll sum=0;
void dfs(int n,int k,ll s) {
    if(n==0) {
        if(s%k==0) {
            sum++;
            sum%=mod;
        }
    }else{
        for(int i=1;i<=6;++i){
            ll ns=s*10+i;
            dfs(n-1,k,ns);
        }
    }
}
int main() {
    int n,k;
    cin>>n>>k;
    dfs(n,k,0);
    cout<<sum;
    return 0;
}

