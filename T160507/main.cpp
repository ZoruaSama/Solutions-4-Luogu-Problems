#include <iostream>
using namespace std;
#define ll long long
int main() {
    ll v,m,a,n;
    cin>>n>>v>>m>>a;
    ll sum=0;
    ll cnt=0;
    for(int i=1;i<=n;++i){
        sum+=v;
        cnt++;
        if(cnt%m==0){
            v+=a;
        }
    }
    cout<<sum;
    // 0 + 1 + 2 + 3 + 4

    return 0;
}
