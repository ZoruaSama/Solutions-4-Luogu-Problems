#include <iostream>
using namespace std;
int m,x,n;
int f[1001][1001]={0};
int main() {
    cin>>n>>m>>x;
    int a,b,c;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>c;
        for(int j=m;j>=b;j--){
            for(int k=x;k>=c;k--){
                f[j][k]=max(f[j][k],f[j-b][k-c]+a);
            }
        }
    }
    cout<<f[m][x];
    return 0;
}
