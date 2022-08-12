#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 50+10;
const int maxm = 50+10;

int mp[maxm][maxn];
int f[maxn+maxm][maxm][maxn];
int m,n;

int main() {
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&mp[i][j]);
        }
    }
    f[1][1][1]=mp[1][1];
    for(int k=1;k<=(m+n);++k){
        for(int i=1;i<k;++i){
            for(int j=1;j<k;++j){
                f[k][i][j]=max(f[k][i][j],f[k-1][i][j]);
                f[k][i][j]=max(f[k][i][j],f[k-1][i-1][j]);
                f[k][i][j]=max(f[k][i][j],f[k-1][i][j-1]);
                f[k][i][j]=max(f[k][i][j],f[k-1][i-1][j-1]);
                if(i==j) f[k][i][j]+=mp[i][k-i];
                else f[k][i][j]+=mp[i][k-i]+mp[j][k-j];
            }
        }
    }
    printf("%d",f[n+m][m][m]);
    return 0;
}
