#include <iostream>
#include <algorithm>
using namespace std;
int f[1000];
int main() {
    int n;
    cin>>n;
    f[0]=0;
    for(int i=1;i<=n;++i){
        f[i]=1e9;
        if(i>=2){
            f[i]=min(f[i-2]+1,f[i]);
        }
        if(i>=5){
            f[i]=min(f[i-5]+1,f[i]);
        }
        if(i>=7){
            f[i]=min(f[i-7]+1,f[i]);
        }
    }
    cout<<f[n];
    return 0;
}
