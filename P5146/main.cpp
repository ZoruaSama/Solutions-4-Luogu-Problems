#include <iostream>
using namespace std;
int n,minn=2e9,maxn=-1,d,ans=0;
int main() {
    cin>>n;
    for(int i=0;i<n;++i) {
        cin >> d;
        if (d < minn) {
            maxn = minn = d;
        }
        if (d > maxn) {
            maxn = d;
        }
    ans = max(ans,maxn-minn);
    }
    cout<<ans;
    return 0;
}
