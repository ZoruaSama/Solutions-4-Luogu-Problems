#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
int ans;
int a[maxn];
struct p{
    int n;
    int id;
}P[maxn];
int lowbit(int x){
    return x&(-x);
}
int add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        a[i]=max(a[i],v);
    }
}
int ask(int x){
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        res=max(res,a[i]);
    }
    return res;
}
bool cmp(p &x,p &y){
    return x.n < y.n;
}
bool cmp_(p &x,p &y){
    return x.id < y.id;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>P[i].n;
        P[i].id=i;
    }
    sort(P+1,P+1+n,cmp);
    for(int i=1;i<=n;++i){
        P[i].n=i;
    }
    sort(P+1,P+1+n,cmp_);
    for(int i=1;i<=n;++i){
        int x=ask(P[i].n-1)+1; //严格递增需要-1
        add(P[i].n,x);
        ans=max(ans,x);
    }
    cout<<n-ans;
    return 0;
}
