#include <iostream>
using namespace std;
const int maxn=25e2+10;
int n,m;
int a[maxn];
int sum[maxn];
int f[maxn];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==2) a[i]=-1;
        sum[i]=sum[i-1]+a[i];
        f[i]=2e9;
    }
    f[0]=0;
    f[1]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i-1;++j){
            if(abs(sum[i]-sum[j-1])==i-j+1 || abs(sum[i]-sum[j-1])<=m){
                //只有一种阵营 || 两种阵营数量差小于m
                f[i]=min(f[i],f[j-1]+1);
                //状态转移方程: 前一个
            }
        }
    }
    cout<<f[n];
    return 0;
}
