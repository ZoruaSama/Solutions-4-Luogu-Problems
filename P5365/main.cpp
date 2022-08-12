#include <iostream>
#define ll long long
using namespace std;
int n,m;
ll k[150];
ll c[150];
ll dp[150][2000];
ll g=0;
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>k[i];
    }
    for(int i=1;i<=n;++i){
        cin>>c[i];
        g+=k[i]*c[i];
    }

    return 0;
}
