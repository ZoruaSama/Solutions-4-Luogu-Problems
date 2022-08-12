#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,p,S;

const int maxw=1e3+10;
const int maxn=1e3+10;
const int maxs=1e3+10;
struct e{
    int w,v;
}E[maxn];
int f[maxs];
int maxk;
bool cmp(e &a,e &b){
    return a.w < b.w;
}
int main() {
    scanf("%d%d%d",&n,&p,&S);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&E[i].w,&E[i].v);
    }
    sort(E+1,E+1+n,cmp);
    for(int i=1;i<=n;++i){
        for(int j=S;j>=E[i].w;--j){
            f[j]=max(f[j],f[j-E[i].w]+E[i].v);
            if(f[j]>=p){
                printf("%d",E[i].w);
                return 0;
            }
        }
    }
    printf("No Solution!");
    return 0;
}
