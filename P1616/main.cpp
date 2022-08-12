#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long t;
    long long m;
    long long ai;
    long long bi;
    long long f[10000001]={0};
    cin>>t>>m;
    for(int i=0;i<m;i++){
        cin>>ai>>bi;
        for(int j=ai;j<=t;j++){
            f[j]=max(f[j],f[j-ai]+bi);
        }
    }
    cout<<f[t];
    return 0;
}