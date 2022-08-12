#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
const int maxn=5e3+10;
double dis(double x1,double y1,double x2,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
double x[maxn],y[maxn],d[maxn];
int vis[maxn];
double ans=0;
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
        d[i]=2e18;
    }
    d[0]=2e18;
    d[1]=0;
    for(int i=1;i<=n;++i){
        int k=0;
        for(int j=1;j<=n;++j){
            if(!vis[j] && d[j]<d[k]) k=j;
        }
        vis[k]=1;
        for(int j=1;j<=n;++j){
            double d_=dis(x[k],y[k],x[j],y[j]);
            if(!vis[j]&&d_<d[j]){
                d[j]=d_;
            }
        }
    }
    for(int i=1;i<=n;++i){
        ans+=sqrt(d[i]);
    }
    printf("%.2lf",ans);
    return 0;
}