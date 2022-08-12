#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=310;
const int maxm=310;
int n,m;
int h[maxn];
int par[maxn];
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(h[x]==h[y]) return ;
    if(h[x]<h[y]){
        merge(y,x);
        return ;
    }
    par[y]=x;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        par[i]=i;
        scanf("%d",h+i);
    }
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        merge(u,v);
    }
    int cnt=0;
    int ans;
    for(int i=1;i<=n;++i){
        if(par[i]==i){
            cnt++;
            ans=i;
        }

    }
    if(cnt>1){
        printf("Non");
    }else{
        printf("Oui, j'ai trouve la solution.\n%d",ans);
    }
    return 0;
}
