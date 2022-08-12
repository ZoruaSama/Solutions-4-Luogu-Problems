#include <iostream>
#include <algorithm>
using namespace std;
int mp[10][10]={0};
int f[10][10][10][10]={0};
int max4(int x,int y,int z,int m){
    return max(max(x,y),max(z,m));
}
int main() {
    //f[i][j][k][l]  A从1,1 到达 i,j 且B从1,1 到达k,l时
    int n;
    cin>>n;
    int x,y,z;
    while(cin>>x>>y>>z){
        if(x==y && y==z && z==0){
            break;
        }
        mp[x][y]=z;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) {
            for(int k=1;k<=n;++k) {
                for(int l=1;l<=n;++l) {
                    f[i][j][k][l]=max4(f[i-1][j][k-1][l],
                            f[i][j-1][k][l-1],
                            f[i][j-1][k-1][l],
                            f[i-1][j][k][l-1])+mp[i][j]+mp[k][l];
                    if(i==k && j==l){
                        f[i][j][k][l]-=mp[i][j];
                    }
                }
            }
        }
    }
    cout<<f[n][n][n][n];
    return 0;
}
