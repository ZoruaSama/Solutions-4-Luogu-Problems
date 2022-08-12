#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn=2e2+10;
int n,m;
int a[maxn],b[maxn];
ll f[maxn];
int main() {
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d",&a[i],&b[i]);
    }
    FOR(i,1,n){
            f[i]=2e18;
    }
    for(int i=1;i<=m;++i){
         for(int j=n;j>=0;--j){
            for(int k=1;k<=j;++k){
                f[j]=min(f[j],(f[j-k]+a[i]*(ll)pow(k,b[i])));
            }
        }
    }
    printf("%d",f[n]);
    return 0;
}
