#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e9+10;
int l,s,t,m;
int p[maxn];
int f[maxn];
int main() {
    scanf("%d%d%d%d",&l,&s,&t,&m);
    for(int i=1;i<=m;++i){
        int a;
        scanf("%d",&a);
        p[a]=1;
    }
    for(int i=1;i<=l;++i){
        f[i]=2e9;
        for(int j=s;j<=t;++j){
            if(i-j>=0) f[i]=min(f[i],f[i-j]+p[i]);
        }
    }
    printf("%d",&f[l]);
    return 0;
}
