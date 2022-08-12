#include <iostream>
#include <cstdio>
using namespace std;
int n;
double b;
struct node{
    double x,y;
    double operator*(node &other){
        return (x*other.y-other.x*y)*0.5;
    }
}nodes[100010];
double fabs(double x){
    if(x>=0){
        return x;
    }else{
        return -x;
    }
}
int main() {
    //freopen("P2785_2.in","r",stdin);
    scanf("%d%lf",&n,&b);
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",&nodes[i].x,&nodes[i].y);
    }
    nodes[n+1]=nodes[1];
    double ans=0;
    for(int i=1;i<=n;++i){
        ans+=nodes[i]*nodes[i+1];
    }
    printf("%.4lf",b*fabs(ans));
    return 0;
}
