#include <iostream>
#include <algorithm>
#define ll long long
const int maxn=8010;
int n,q;
ll a,b,c,d;
struct cir_t{
    ll x,y,r,z;
    bool vis;
}cir[maxn];
using namespace std;
bool cmp(cir_t c1,cir_t c2){
    return c1.z<c2.z;
}
ll dist(ll x1,ll y1,ll x2,ll y2){
    return (x1-y1)*(x1-y1)+(x2-y2)*(x2-y2);
}
//求离得最近的且包含的圆
int close(ll x,ll y){

}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>cir[i].x>>cir[i].y>>cir[i].r;
        cir[i].vis=false;
    }
    sort(cir+1,cir+1+n,cmp);
    cin>>q;
    while(q--){

    }
    return 0;
}
