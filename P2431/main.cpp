#include <iostream>
#define ll long long
using namespace std;
ll a,b;
ll ans;
int main() {
    cin>>a>>b;
    while((a|(a+1))<=b) a|=a+1;
    while(a) ans+=a&1,a>>=1;
    cout<<ans;
    return 0;
}
