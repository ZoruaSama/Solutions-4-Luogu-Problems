#include <iostream>
using namespace std;
int v,m,n;
int tj,zl,kll;
int f[401][401];
int main() {
    cin>>v>>m>>n;
    for(int i=1;i<=n;++i){
        cin>>tj>>zl>>kll;
        for(int j=v;j>=tj;--j){
            for(int k=m;k>=zl;--k){
                f[j][k]=max(f[j][k],f[j-tj][k-zl]+kll);
            }
        }
    }
    cout<<f[v][m];
    return 0;
}
