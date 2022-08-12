#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n;
int d[maxn];
// d[i]记录第i头牛 和 第i+1头牛的距离
// d[n]记录第n头牛 和 第1头牛的距离
int c;//周长
int f[maxn];
int main() {
    scanf("%d%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",d+i);
        c+=d[i];
    }
    for(int i=1;i<=n;++i){
        f[i]=min()
    }
    return 0;
}
