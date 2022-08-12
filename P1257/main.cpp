#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
const int maxn=1e4+10;
struct p{
    double x,y;
}P[maxn];
int temp[maxn];
bool cmp(p &a,p &b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmpt(int &a,int &b){
    return P[a].y<P[b].y;
}
double ans=0;
double dist(int a,int b){
    double x1,y1,x2,y2;
    x1=P[a].x;
    y1=P[a].y;
    x2=P[b].x;
    y2=P[b].y;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double merge(int l,int r){
    double dis=2e9;
    if(l==r) return dis;
    if(l+1==r) return dist(l,r);
    int mid=(l+r)>>1;
    double d1=merge(l,mid);
    double d2=merge(mid+1,r);
    dis=min(d1,d2);
    int k=0;
    for(int i=l;i<=r;++i){
        if(fabs(P[i].x-P[mid].x)<=dis){
            temp[++k]=i;
        }
    }
    sort(temp+1,temp+1+k,cmpt);
    for(int i=1;i<=k;++i){
        for(int j=i+1;j<=k &&P[temp[j]].y-P[temp[i]].y<dis;++j){
            dis=min(dis,dist(temp[i],temp[j]));
        }
    }
    return dis;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",&P[i].x,&P[i].y);
    }
    sort(P+1,P+1+n,cmp);
    ans=merge(1,n);
    printf("%.4lf",ans);
    return 0;
}
