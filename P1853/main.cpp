#include <iostream>
#include <cstdio>
using namespace std;
const int maxd=15;
const int maxs=1e7+10;
const int maxn=45;
int s,n,d;
int a[maxd],b[maxd];
int f[maxs];
int main() {
    scanf("%d%d%d",&s,&n,&d);
    for(int i=1;i<=d;++i){
        scanf("%d%d",a+i,b+i);
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=d;++i){
            for(int j=a[i];j<=s;++j){
                f[j]=max(f[j],f[j-a[i]]+b[i]);
            }
        }
        s+=f[s];
    }
    printf("%d",s);
    return 0;
}
