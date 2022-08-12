#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e7+10;
int Ts_h,Ts_m,Te_h,Te_m;
int t,n;
int T[maxn],C[maxn],P[maxn];
int tot;
int f[1010];
int main() {
    scanf("%d:%d",&Ts_h,&Ts_m);
    scanf("%d:%d",&Te_h,&Te_m);
    scanf("%d",&n);
    t = Te_h*60 + Te_m - Ts_h*60 - Ts_m;
    for(int i=1;i<=n;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c==0){
            c=t/a;
        }
        for(int j=1;j<=c;j*=2){
            ++tot;
            T[tot]=j*a;
            C[tot]=j*b;
            c-=j;
        }
        if(c){
            ++tot;
            T[tot]=c*a;
            C[tot]=c*b;
        }
    }
    for(int i=1;i<=tot;++i){
        for(int j=t;j>=T[i];--j){
            f[j]=max(f[j],f[j-T[i]]+C[i]);
        }
    }
    printf("%d",f[t]);
    return 0;
}
