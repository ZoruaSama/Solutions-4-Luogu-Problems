#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll cal(ll x,ll y){
    return (x-y)*(x-y);
}
int n;
ll h[301];
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>h[i];
    }
    sort(h+1,h+1+n);
    ll sum=0;
    int l=1,r=n;
    ll now=0;
    while(l<=r){
        if(l<=r){
            sum+=cal(now,h[r]);
            now=h[r];
            r--;
        }
        if(l<=r){
            sum+=cal(now,h[l]);
            now=h[l];
            l++;
        }
    }
    cout<<sum;
    return 0;
}
