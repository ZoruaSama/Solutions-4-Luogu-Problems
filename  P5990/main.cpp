#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int n;
ll a[1000005];
int main(){
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    int k=n;
    if(n==1 && a[1]%2==1) {cout<<"NIESTETY";return 0;}
    while(sum%2==1 && k>=0){
        while(k>0 && a[n-k+1]%2!=1){
            k--;
        }
        if(n-k+1>=1){
            sum-=a[n-k+1];
            k--;
        }
    }
    cout<<sum;
    return 0;
}