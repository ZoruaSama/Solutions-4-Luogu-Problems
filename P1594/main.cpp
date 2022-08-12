#include <iostream>
#include <cstdio>
using namespace std;
int m,l,n;
const int maxn=1e3+10;
int w[maxn],s[maxn];
double t[maxn];
double f[maxn][maxn];
int main() {
    scanf("%d%d%d",&m,&l,&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",w+i,s+i);
        t[i]=l*1.0/s[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++i){
            f[i][j]=2e9;
        }
    }
    for(int i=1;i<=n;++i){
        f[i][1]=t[i];
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j+i<=n;++j){
            for(int k=1;k<=i;++k){
                f[j][i]=min(f[j][i],f[j][k]+f[j+k][i-k]);
            }
        }
    }
    return 0;
}
