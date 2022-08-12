#include <iostream>
using namespace std;
const int maxt=110;
const int maxn=110;
const int maxm=1e3+10;
int t,n,m;
int p[maxt][maxn];
int main() {
    scanf("%d%d%d",&t,&n,&m);
    for(int i=1;i<=t;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&p[i][j]);
        }
    }
    return 0;
}
