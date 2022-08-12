#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=510;
const int maxm=510;
int n,m;
int yeyenum[maxn][maxm];
int bloggium[maxn][maxm];
int sum1[maxn][maxm];
int sum2[maxn][maxm]; // 前缀和
int f[maxn][maxm];
int main() {
    while(true){
        scanf("%d%d",&n,&m);
        if(n+m==0){
            break;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&yeyenum[i][j]);
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&bloggium[i][j]);
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                sum1[i][j]=sum1[i][j-1]+yeyenum[i][j];
                sum2[i][j]=sum2[i-1][j]+bloggium[i][j];
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                f[i][j]=max(f[i][j-1]+sum2[i][j],f[i-1][j]+sum1[i][j]);
            }
        }
        printf("%d\n",f[n][m]);
    }
    return 0;
}
