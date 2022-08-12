#include <iostream>
#define ll long long
using namespace std;
int mod = 1e9+7;
unsigned long long f[100001]={0};
//因为数据量太大了 所以要用逆元
//https://www.cnblogs.com/adelalove/p/9184723.html
long long ny(ll x,ll y)
{
     ll ans=1;
     while(y)
     {
         if(y&1) ans=ans*x%mod;
         y>>=1;
         x=x*x%mod;
     }
    return ans%mod;
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<=n;++i){
        if(i==0||i==1){
            f[i]=1;
            continue ;
        }
        //f[i]=f[i-1]*(4*i-2)/(i+1);
        f[i]=f[i-1]*(4*i-2)%mod*ny(i+1,mod-2)%mod;
        //cout<<f[i]<<' ';
    }
    cout<<f[n];
    return 0;
}
