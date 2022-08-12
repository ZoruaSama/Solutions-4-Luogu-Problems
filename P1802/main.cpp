#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,x;
    long long lose[1001],win[1001],use[1001];
    long long  f[1001]={0};
    cin>>n>>x;
    for(int i=0;i<n;++i){
        cin>>lose[i]>>win[i]>>use[i];
    }
    for(int i=0;i<n;++i){
        for(int j=x;j>=0;--j){
            if(j>=use[i]){
                f[j]=max(f[j]+lose[i],f[j-use[i]]+win[i]);
            }else{
                f[j]=max(f[j],f[j]+lose[i]);
            }
        }
    }

    cout<<5*f[x];
    return 0;
}