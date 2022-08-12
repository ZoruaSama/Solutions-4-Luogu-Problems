#include <iostream>
#include <algorithm>
#define ll long long
int n,m;
using namespace std;
const int maxn=3e5+10;
ll t[maxn];
ll cnt;
int lowbit(int x){
    return x&(-x);
}
struct a{
    ll v,pos;
    bool operator<(const a &other) const{
        return v < other.v;
    }
}A[maxn];
struct lr{
    int l,r;
    ll id;
    bool operator<(const lr &other) const{
        return r < other.r;
    }
}LR[maxn],LR_[maxn*2];
void update(int x){
    for(int i=x;i<=n;i+=lowbit(i)){
        t[i]++;
    }
}
ll query(int x){
    ll ans=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        ans+=t[i];
    }
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>A[i].v;
        A[i].pos=i;
    }
    sort(A+1,A+1+n);
    A[0].v=A[n+1].v=-0x3f3f3f3f;
    for(int i=1;i<=n;++i){
        ll d1=abs(A[i].v-A[i-1].v);
        ll d2=abs(A[i].v-A[i+1].v);
        if(d1==d2){
            ++cnt;
            LR_[cnt].l=min(A[i].pos,A[i-1].pos);
            LR_[cnt].r=max(A[i].pos,A[i-1].pos);
            ++cnt;
            LR_[cnt].l=min(A[i].pos,A[i+1].pos);
            LR_[cnt].r=max(A[i].pos,A[i+1].pos);
        }else if(d1<d2){
            ++cnt;
            LR_[cnt].l=min(A[i].pos,A[i-1].pos);
            LR_[cnt].r=max(A[i].pos,A[i-1].pos);
        }else{
            ++cnt;
            LR_[cnt].l=min(A[i].pos,A[i+1].pos);
            LR_[cnt].r=max(A[i].pos,A[i+1].pos);
        }
    }
    for(int i=1;i<=m;++i){
        cin>>LR[i].l>>LR[i].r;
        LR[i].id=i;
    }
    sort(LR+1,LR+1+m);
    sort(LR_+1,LR_+1+cnt);
    ll ans=0;
    for(int i=1,j=1;j<=m;++j){
        while(LR_[i].r <=LR[j].r && i<=cnt) update(LR_[i++].l);
        ans+=(query(LR[j].r)-query(LR[j].l-1))*LR[j].id;
    }
    cout<<ans;
    return 0;
}
