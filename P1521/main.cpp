#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[5000][5000];
int main()
{
    cin>>n>>k;
    f[1][0]=1;
    f[2][1]=1;
    f[2][0]=1;
    f[0][0]=1;
    //f[5][3]=f[4][3]+f[4][2]+f[4][1]
    //X1X3X2X4X
    for (int i=3;i<=n;i++){
        for (int j=0;j<=k;j++){
            for (int l=0;l<=i-1 && j-l>=0;l++){
                f[i][j]+=f[i-1][j-l];
                f[i][j]%=10000;
            }
        }
    }
    cout<<f[n][k];
    return 0;
}