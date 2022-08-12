#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
int main(){
    scanf("%lld",&n);
    if(!(n&1)) n++,ans=n;
    ll num=(n+1ll)/2ll;
    if(num&1) ans^=1;
    cout<<ans;
}