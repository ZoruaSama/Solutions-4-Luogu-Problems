#include <iostream>
using namespace std;
long long f[501][501]; //跑了i圈 最后一次跑了j圈的方案数
int n;
int main() {
    cin>>n;
    cin>>n;
    for(int i=1;i<=n;++i){
        f[i][i]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            for(int k=1;k<j && j+k<=i;++k){
                f[i][j]+=f[i-j][k];
            }
        }
    }
    long long res=0;
    for(int i=1;i<n;++i){
        res+=f[n][i];
    }
    cout<<res;
    return 0;
}
