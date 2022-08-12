#include <iostream>
using namespace std;
int f[1001][1001];
int n,m;

int main() {
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            f[i][j]=-1;
        }
    }
    f[1][1]=1;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        f[a][b]=0;
    }
    for(int i=2;i<=n;++i){
        if(f[i][1]!=0){
            f[i][1]=f[i-1][1];
        }
        if(f[1][i]!=0){
            f[1][i]=f[1][i-1];
        }
    }
    for(int i=2;i<=n;++i){
        for(int j=2;j<=n;++j){
            if(f[i][j]!=0){
                f[i][j]=(f[i-1][j]+f[i][j-1])%100003;
            }
        }
    }
    cout<<f[n][n]%100003;
    return 0;
}
