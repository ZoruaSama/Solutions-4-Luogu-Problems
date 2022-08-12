#include <iostream>
using namespace std;
int main() {
    int n,d,ans=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>d;
        ans ^= d;
    }
    cout<<ans;
    return 0;
}
