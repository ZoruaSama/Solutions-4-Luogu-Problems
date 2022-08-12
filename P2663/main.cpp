#include <iostream>
using namespace std;
int n;
int s[101];
int f[101][10010];
int sum=0;
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        sum+=s[i];
    }
    sum/=2;
    f[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=sum;j>=s[i];--j){
            for(int k=n/2;k>=1;--k){
                f[k][j]|=f[k-1][j-s[i]];
            }
        }
    }
    for(int i=sum;i>=0;--i){
        if(f[n/2][i]){
            cout<<i;
            break;
        }
    }
    return 0;
}
