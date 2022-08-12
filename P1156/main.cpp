#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxd=110;
const int maxt=1010;
const int maxh=30;
const int maxf=35;
const int maxg=110;
int d,g;
struct e{
    int t,f,h;
}E[maxg];
int f[maxd][maxh*4];
int res=-1;
bool cmp(e &a,e &b){
    return a.t < b.t;
}
int main() {
    scanf("%d%d",&d,&g);
    for(int i=1;i<=g;++i){
        scanf("%d%d%d",&E[i].t,&E[i].f,&E[i].h);
    }
    sort(E+1,E+1+g,cmp);
    for(int i=g;i>=1;--i){
        E[i].t -= E[i-1].t;
    }
    for(int i=1;i<=g;++i){
        for(int j=d;j>=E[i].h;--j){
            for(int k=maxh*4;k>=0;--k){
                f[j][k]=max(f[j][k],f[j-E[i].h][k+E[i].t]+E[i].t);
                f[j][k]=max(f[j][k],f[j][k+E[i].t-E[i].h]+E[i].t);
            }
        }
    }
    for(int i=1;i<=maxh*4;++i){
        res=max(res,f[d][i]);
    }
    printf("%d",res);
    return 0;
}
