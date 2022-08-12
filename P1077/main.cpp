#include <iostream>
#include <algorithm>
using namespace std;
long long f[101][101]={0};
// f[i][j] 在剩下的 j 堆里选出 和 为 i 的方法数量。
int main() {

    int n,m,d[101];
    cin>>n>>m;
    for(int i=0;i<n;++i) {
     cin>>d[i];
    }
    int i,j,k;
    for(i=0;i<=m;++i){
        for(j=1;j<=n;++j){
            if(j==1){
                if( d[n-1] >= i)
                    f[i][j]=1;
                else
                    f[i][j]=0;
            }
            else if(i==0){
                f[i][j]=1;
            }
            else{
                for(k=0;k<=min(d[n-j],i);++k)
                    f[i][j]+=f[i-k][j-1];
                    f[i][j]%=1000007;
            }

        }

    }

    cout<<f[m][n]%1000007;
    return 0;
}
