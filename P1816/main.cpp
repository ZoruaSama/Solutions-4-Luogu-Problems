#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100001;
int f[maxn][20];
int len[maxn]={0};
int main(){
    int m,n;
    //freopen("P1816.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=maxn;++i){
        len[i]=(int)log2(i);
    }
    for(int i=1;i<=m;++i){
        scanf("%d ",&f[i][0]);
    }
    for(int j=1;(1<<j)<=m;++j){
        for(int i=1;i+(1<<j)-1<=m;++i){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        int k=len[b-a+1];
        printf("%d ",min(f[a][k],f[b-(1<<k)+1][k]));
    }
    return 0;
}