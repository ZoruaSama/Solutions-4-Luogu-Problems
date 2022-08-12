#include <iostream>
#include <cstdio>
using namespace std;
long long inv[3000001];
int main() {
    int n,p;
    cin>>n>>p;
    inv[1]=1;
    cout<<1<<endl;
    for(int i=2;i<=n;++i){
        inv[i] = (p-p/i)*inv[p%i]%p;
        printf("%lld\n",inv[i]);
    }
    return 0;
}
