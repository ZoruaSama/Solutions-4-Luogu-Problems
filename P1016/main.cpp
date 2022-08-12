#include <iostream>
#include <cstdio>
#define db double
using namespace std;
int n;
db d1,c,d2;
db d[10];
db p[10];
double ans;
int main() {
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,p,&n);
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",d+i,p+i);
    }
    d[n+1]=d1;
    for(int i=0;i<=n;++i){
        db dist = d[i+1]-d[i];
        if(dist>c*d2){
            printf("No Solution");
            return 0;
        }
        ans+=dist/d2*p[i];
    }
    printf("%.2lf",ans);
    return 0;
}
