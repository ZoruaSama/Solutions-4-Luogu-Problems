#include <iostream>
using namespace std;
int f[101][101]={0};
int a[101][101]={0};
//f[i][j]表示以节点i,j为右下角，可构成的最大正方形的边长。
int res=-1;
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    f[1][1]=a[1][1];
    f[1][2]=a[1][1];
    f[2][1]=a[1][1];
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            if(a[i][j]==1){
                f[i][j]=min(f[i-1][j-1],min(f[i][j-1],f[i-1][j]))+1;
                res=max(res,f[i][j]);
            }
        }
    }

    cout<<res;
    return 0;
}
