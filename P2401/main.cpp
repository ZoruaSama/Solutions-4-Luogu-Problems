#include <iostream>
using namespace std;
int f[1001][1001]={0};
int mod=2015;
//f[i][j]表示前i个数中恰有j个<的方案数.
int main() {
    int n,k;
    cin>>n>>k;
    f[1][0]=1;
    for(int i=2;i<=n;++i){
        f[i][0]=1;
        for(int j=1;j<=k;++j){
            f[i][j]=f[i-1][j]*(j+1)+f[i-1][j-1]*(i-j);
            f[i][j]%=mod;
        }
    }
    cout<<f[n][k];
    return 0;
}
