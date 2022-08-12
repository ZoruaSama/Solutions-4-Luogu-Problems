#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int s,d,m;
const int maxs=55;
const int maxd=15;
const int maxm=2e5+10;
int p[maxs][maxd];
int f[maxm];
int main() {
    scanf("%d%d%d",&s,&d,&m);
    for(int i=1;i<=s;++i){
        for(int j=1;j<=d;++j){
            scanf("%d",&p[i][j]);
        }
    }
    for(int i=2;i<=d;++i){
        int res=0;
        memset(f,0,sizeof(f));
        for(int j=1;j<=s;++j){
            for(int k=p[j][i-1];k<=m;++k){
                f[k]=max(f[k],f[k-p[j][i-1]]+p[j][i]-p[j][i-1]);
                res=max(res,f[k]);
            }
        }
        m+=res;
    }
    printf("%d",m);
    return 0;
}
