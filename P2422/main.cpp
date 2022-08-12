#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n;
ll a[maxn];
ll sum[maxn];
ll minf[maxn][30];
ll pos[maxn][30];
ll ij[maxn];
ll ans;
void find(int l,int r){
    if(l>r) return ;
    ll mid=0;
    ll k=ij[r-l+1];
    ll s=sum[r]-sum[l-1];
    ll minff=0;
    if(minf[l][k] >= minf[r-(1<<k)+1][k]){
        minff=minf[r-(1<<k)+1][k];
        mid=pos[r-(1<<k)+1][k];
    }else{
        minff=minf[l][k];
        mid=pos[l][k];
    }
    ans=max(ans,s*minff);
    find(l,mid-1);
    find(mid+1,r);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        minf[i][0]=a[i];
        pos[i][0]=i;
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;(1<<i)<=n;++i){
        for(int j=1;j+(1<<i)-1<=n;++j){
            minf[j][i]=min(minf[j][i-1],minf[j+(1<<(i-1))][i-1]);
            if(minf[j][i-1] > minf[j+(1<<(i-1))][i-1]){
                pos[j][i]=pos[j+(1<<(i-1))][i-1];
            }else{
                pos[j][i]=pos[j][i-1];
            }
        }
    }
    for(int i=1;i<=n;++i){
        ij[i]=(int)log2(i);
    }
    find(1,n);
    cout<<ans;
    return 0;
}
