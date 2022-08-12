#include <iostream>
#include <algorithm>

using namespace std;
int w[3410],d[3410];
int f[13000]={0};
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>w[i]>>d[i];
    }
    for(int i=0;i<n;++i){
        for(int j=m;j>=w[i];--j){
            f[j]=max(f[j-w[i]]+d[i],f[j]);
        }
    }

    cout<<f[m]<<endl;

    return 0;
}
