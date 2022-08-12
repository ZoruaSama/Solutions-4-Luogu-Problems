#include <iostream>
using namespace std;
int T[501],V[501],G[501];
int f[501][501];
int main() {
    int v,g;
    int n;
    cin>>v>>g>>n;
    for(int i=1;i<=n;++i){
        cin>>T[i]>>V[i]>>G[i];
        for(int j=v;j>=V[i];--j){
            for(int k=g;k>=G[i];--k){
                f[j][k]=max(f[j-V[i]][k-G[i]]+T[i],f[j][k]);
            }
        }
    }
    cout<<f[v][g];
    return 0;
}
