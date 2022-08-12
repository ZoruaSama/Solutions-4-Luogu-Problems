#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    signed int n,m;
    int a[2001][2001];
    int f[2001][2001];
    cin>>n>>m;//n是任务数  m是组
    for(int i=0;i<m;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    //边界条件
    for(int i=0;i<m;++i){
        f[1][i]=a[i][1];
    }
    /*

             4 3
             2 6 1 8
             3 6 2 6
             4 2 3 6
             f[1][0]=2 f[1][1]=3 f[1][2]=4
             f[2][0]= min(f[1][0] + 2,f[1][2] + 2)
             f[2][1]= min(f[1][1] + 6,f[1][0] + 6)
             f[2][2]= min(f[1][2] + 6,f[1][1] + 6)

             f[i][j]= min(f[i-1][j],f[i-1][(j+m-1) % m]) + a[i][j];
             */
    for(int i=2;i<=n;++i){
        for(int j=0;j<m;++j){
            f[i][j]= min(f[i-1][j],f[i-1][(j+m-1) % m]) + a[j][i];
        }
    }

    int res=f[n][0];
    for(int j=0;j<m;++j){
        res=min(res,f[n][j]);
    }
    cout<<res;

    return 0;
}
