#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e3+10;
const int maxm=1e3+10;
int n,m;
int p[maxn][maxm];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&p[i][j]);
        }
    }
    return 0;
}
