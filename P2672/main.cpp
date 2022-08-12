#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
int sum[maxn],q[maxn],h[maxn];
struct e{
    int s,a;
    bool operator<(e &other)const{
        return a<other.a;
    }
}E[maxn];
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>E[i].s;
    }
    for(int i=1;i<=n;++i){
        cin>>E[i].a;
    }
    sort(E+1,E+1+n);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+E[i].a;
    }
    for(int i=1;i<=n;++i){
        q[i]=max(q[i-1],2*E[i].s);
    }
    for(int i=n;i>=1;--i){
        h[i]=max(h[i+1],2*E[i].s+E[i].a);
    }
    for(int i=1;i<=n;++i){
        cout<<max(sum[i]+q[i],sum[i-1]+h[i])<<endl;
    }
    return 0;
}
