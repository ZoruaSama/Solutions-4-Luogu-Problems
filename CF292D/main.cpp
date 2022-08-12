#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=510;
const int maxm=1e4+10;

int n,m,k;

struct dsu{
    int par[maxn];
    int cnt;
    int find(int x){
        return par[x] ? par[x]=find(par[x]):x;
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x!=y){
            par[x]=y;
            cnt++;
        }
    }
}L[maxm],R[maxm],ans;
int u[maxm],v[maxm];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d",u+i,v+i);
        L[i]=L[i-1];
        L[i].merge(u[i],v[i]);
    }
    for(int i=m;i>0;--i){
        R[i]=R[i+1];
        R[i].merge(u[i],v[i]);
    }
    scanf("%d",&k);
    while(k--){
        int l,r;
        scanf("%d%d",&l,&r);
        ans=L[l-1];
        for(int i=1;i<=n;++i){
            if(R[r+1].par[i]) ans.merge(i,R[r+1].par[i]);
        }
        printf("%d\n",n-ans.cnt);
    }
    return 0;
}
