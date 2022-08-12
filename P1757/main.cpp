#include <iostream>
using namespace std;
int main() {
    int m,n;
    const int maxn=1010;
    int w[maxn],v[maxn],g[maxn];
    int f[maxn][maxn]={0};
    int ff[maxn]={0};
    // f[i][j] 表示 第i组分配j个空间时 价值的最优解
    int kk=0;
    cin>>m>>n;
    for(int i=0;i<n;++i){
        cin>>w[i]>>v[i]>>g[i];
        kk=max(kk,g[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=m;j>=w[i];--j){
            f[g[i]][j]=max(f[g[i]][j],v[i]);
        }
    }
    for(int i=0;i<=kk;++i){ //对于每个组
        for(int j=m;j>=0;--j){ //对于每种空间
            for(int k=0;k<=j;++k){  // 形成分配方案
                ff[j]=max(ff[j],ff[j-k]+f[i][k]);
            }
        }
    }
    cout<<ff[m];
    return 0;
}
