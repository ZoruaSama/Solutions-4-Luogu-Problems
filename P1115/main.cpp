#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int a;
    int f[200001];
    int ans=-9e7;
    cin>>n;
    cin>>f[1];
    for(int i=2;i<=n;++i){
        cin>>a;
        f[i]=max(f[i-1]+a,a);
    }
    for(int i=1;i<=n;++i){
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}
