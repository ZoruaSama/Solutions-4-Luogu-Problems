#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
ll n,l,r;
int main() {
    scanf("%d",&n);
    l=1,r=2e9;
    while(l<r){
        ll mid=(l+r)/2;
        ll len=(ll)(mid*log10(1.0*mid))+1;
        if(len<n){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}
