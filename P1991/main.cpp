#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int s,p;
const int maxn=510;
struct e{
    int u,v;
    double w;
    bool operator<(const e &other) const{
        return w<other.w;
    }
}E[maxn*maxn],E_[maxn];
int tot;
int par[maxn];
int spe[maxn];
double dis(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
int main() {
    //cin>>s>>p;
    double ans=0;
    scanf("%d%d",&s,&p);
    int x[maxn],y[maxn];
    for(int i=1;i<=p;++i){
        scanf("%d%d",&x[i],&y[i]);
        //cin>>x[i]>>y[i];
        par[i]=i;
    }
    for(int i=1;i<=p;++i){
        for(int j=i+1;j<=p;++j){
            E[++tot].u=i;
            E[tot].v=j;
            E[tot].w=dis(x[i],y[i],x[j],y[j]);
        }
    }
    sort(E+1,E+1+tot);
    int cnt=0;
    for(int i=1;i<=tot;++i){
        int u = find(E[i].u);
        int v = find(E[i].v);
        if(u != v){
            par[u]=v;
            cnt++;
            E_[cnt].u=E[i].u;
            E_[cnt].v=E[i].v;
            E_[cnt].w=E[i].w;
            if(cnt==p-1){ //生成树完毕
                //ans=E[i].w;
                break;
            }
        }
    }

    for(int i=cnt;i>0 && s>0;i--){
        if(s>=2 && !spe[E_[i].u] && !spe[E_[i].v]){
            s-=2;
            spe[E_[i].u]=1;
            spe[E_[i].v]=1;
        }else if(s>=1 && spe[E_[i].u] && !spe[E_[i].v]){
            s-=1;
            spe[E_[i].v]=1;
        }else if(s>=1 && !spe[E_[i].u] && spe[E_[i].v]){
            s-=1;
            spe[E_[i].u]=1;
        }
    }
    for(int i=1;i<=p;++i){
        if(spe[i]) cout<<i<<endl;
    }
    for(int i=1;i<=cnt;++i){
        if(spe[E_[i].u] && spe[E_[i].v]){
            cout<<E_[i].w<<endl;
            E_[i].w=0;
        }
        ans=max(ans,E_[i].w);
    }
    printf("%.2lf",ans);
    return 0;
}
