#include <iostream>
using namespace std;
long long f[10001]={1};
int h[26];
int main() {
    int n,v;
    cin>>v>>n;
    for(int i=1;i<=v;++i){
        cin>>h[i];
    }
    for(int i=1;i<=v;++i){
        for(int j=h[i];j<=n;++j){
            f[j]+=f[j-h[i]];
        }
    }
    cout<<f[n];
    return 0;
}
