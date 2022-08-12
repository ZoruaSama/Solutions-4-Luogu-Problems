#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1010;
int n;
struct e{
    int to,from,w;
}E[maxn*maxn];
int par[maxn];
int tot;
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void addLine(int u,int v,int w){
    E[++tot].to=v;
    E[tot].w=w;
    E[tot].from=u;
}
bool cmp(e &a,e &b){
    return a.w<b.w;
}
int x[maxn],y[maxn];
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
        par[i]=i;
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            addLine(i,j,w);
            addLine(j,i,w);
        }
    }
    sort(E+1,E+1+tot,cmp);
    int cnt=0;
    for(int i=1;i<=tot;++i){
        int p1=find(E[i].from);
        int p2=find(E[i].to);
        if(p1!=p2){
            par[p2]=p1;
            cnt++;
            if(cnt==n-1){
                cout<<E[i].w;
                break;
            }
        }
    }
    return 0;
}
