#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n,W;
int v[maxn],w[maxn],m[maxn];
int f[maxn];
int tot;
int main() {
    scanf("%d%d",&n,&W);
    for(int i=1;i<=n;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for(int j=1;j<=c;j*=2){
            ++tot;
            v[tot]=j*a;
            w[tot]=j*b;
            c-=j;
        }
        if(c){
            ++tot;
            v[tot]=c*a;
            w[tot]=c*b;
        }
    }
    for(int i=1;i<=tot;++i){
        for(int j=W;j>=w[i];--j){
             f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }
    printf("%d",f[W]);
    return 0;
}
