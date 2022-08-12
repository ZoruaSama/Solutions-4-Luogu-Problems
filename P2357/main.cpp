#include <iostream>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int n,f;
ll a[maxn],d[maxn];
int lowbit(int x){
    return x&(-x);
}
void add(int x,ll k){
    for(int i=x;i<=n;i+=lowbit(i)){
        a[i]+=k;
        d[i]+=x*k;
    }
}
ll ask(int x){
    ll res=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        res+=(x+1)*a[i]-d[i];
    }
    return res;
}

int main() {
    cin>>n>>f;
    int q[maxn];
    for(int i=1;i<=n;++i){
        cin>>q[i];
    }
    for(int i=n;i>=1;--i){
        q[i]=q[i]-q[i-1];
        add(i,q[i]);
    }
    int c,l,r,k;
    for(int i=1;i<=f;++i){
        cin>>c;
        if(c==1){
            cin>>l>>r>>k;
            add(r+1,-k);
            add(l,k);
        }else if(c==2){
            cin>>k;
            add(2,-k);
            add(1,k);
        }else if(c==3){
            cin>>k;
            add(2,k);
            add(1,-k);
        }else if(c==4){
            cin>>l>>r;
            cout<<ask(r)-ask(l-1)<<endl;
        }else{
            cout<<ask(1)-ask(0)<<endl;
        }
    }
    return 0;
}
