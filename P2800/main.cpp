#include <iostream>
using namespace std;
int main() {
    int f[1000005];
    int a[1000005];
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        f[i]=1e9;
    }
    f[n+1]=1e9;
    for(int i=1;i<=n+1;++i){
        f[i]=min(f[i],f[i-1]);
        f[i]=min(f[i],f[i-2]);
        f[i]=min(f[i],f[i-3]);
        f[i]+=a[i];
    }
    cout<<f[n+1];
    return 0;
}
