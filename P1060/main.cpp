#include <iostream>
using namespace std;

int main() {
    int n,m;
    int v[25],w[25],f[30000]={0};
    //价格和重要度的乘积总和最大
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>v[i]>>w[i];
    }
    for(int j=0;j<m;j++){
        for(int i=n;i>=0;i--){
            if(i>=v[j])
                f[i] = max(f[i],f[i-v[j]]+v[j]*w[j]);
        }
    }
    cout<<f[n];
    return 0;
}
