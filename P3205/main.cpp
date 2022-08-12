#include <iostream>
using namespace std;
const int maxn=1010;
const int mod=19650827;
int n;
int s[maxn];
int f[maxn][maxn];
//区间[i,i+j] 最后一个加入的数是i的情况数
int g[maxn][maxn];
//区间[i,i+j] 最后一个加入的数是j的情况数
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        f[i][1]=1;
        //g[i][1]=1;  f+g只有一种 所以不用再写这个。
    }
  for(int j=2;j<=n;++j){
    for(int i=1;i+j-1<=n;++i){
            //cout<<i<<' '<<i+j-1<<endl;
            if(s[i]<s[i+1]) f[i][j]+=f[i+1][j-1]; //前一个排进去的是i+1
            if(s[i]<s[i+j-1]) f[i][j]+=g[i+1][j-1]; //前一个排进去的是j
            f[i][j]%=mod;
            if(s[i+j-1]>s[i]) g[i][j]+=f[i][j-1];  //前一个排进去的是i
            if(s[i+j-1]>s[i+j-2]) g[i][j]+=g[i][j-1];//前一个排进去的是j-1
            g[i][j]%=mod;
    }
  }
    cout<<(f[1][n]+g[1][n])%mod;
    return 0;
}
