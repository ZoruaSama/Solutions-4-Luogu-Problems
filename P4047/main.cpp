#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,k;
const int maxn=1010;
struct e{
    int u,v;
    double w;
}E[maxn*maxn];
struct p{
    int x,y;
}P[maxn];
int par[maxn];
int tot;
double ans;
void addEdge(int u,int v,double w){
    E[++tot].u=u;
    E[tot].v=v;
    E[tot].w=w;
}
double dist(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void merge(int x,int y){
    par[find(x)]=find(y);
}
bool cmp(e &a,e &b){
    return a.w<b.w;
}
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}
int main() {
    n=read();k=read();
    for(int i=1;i<=n;++i){
        P[i].x=read();
        P[i].y=read();
        par[i]=i;
    }
    int m=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            addEdge(i,j,dist(P[i].x,P[i].y,P[j].x,P[j].y));
            m++;
        }
    }
    sort(E+1,E+1+m,cmp);
    int cnt=0;
    for(int i=1;i<=m;++i){
        int u = E[i].u; int v=E[i].v;
        if(find(u)!=find(v)){
            merge(u,v);
            cnt++;
            if(cnt==n-k+1){ //总共需要n-1条边把所有点连起来 部落间的k-1条线是最后连的 (n-1)-(k-1)+1
                ans=E[i].w;
            }
        }
    }
    printf("%.2lf",ans);
    return 0;
}
