#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
LL mp[200][200]={0};
LL f[200][200]={0};
int main() {
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<n;++i){
        if(abs(i-n/2)<=1){
            f[m-1][i]=mp[m-1][i];
        }
        else{
            f[m-1][i]=-2e10;
        }
    }
    for(int i=m-2;i>=0;--i){
        for(int j=0;j<n;++j){
            LL max3=f[i+1][j];
            if(j-1>=0){
                max3=max(max3,f[i+1][j-1]);
            }
            if(j+1<n){
                max3=max(max3,f[i+1][j+1]);
            }
            f[i][j]=max3+mp[i][j];
        }
    }
    LL res=0;
    for(int i=0;i<n;++i){
        res=max(f[0][i],res);
    }
    cout<<res;
    return 0;
}
