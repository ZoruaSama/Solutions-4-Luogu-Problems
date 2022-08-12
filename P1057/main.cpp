#include <iostream>
using namespace std;
int main() {
    int n,m;
    int f[31][31]={0};
    cin>>n>>m;
    f[0][1]=1;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            int t=i-1;
            if(t==0) t=n;
            f[j][i]=f[j-1][t]+f[j-1][i%n+1];
        }
    }
    cout<<f[m][1];
    return 0;
}
