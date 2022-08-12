#include <iostream>
#include <algorithm>
using namespace std;
int f[5001]={0};
int main() {
    int n;
    cin>>n;
    if(n==0){
        cout<<0;
    }else{
        f[0]=0;
        for(int i=1;i<=n;++i){
            f[i]=2e9;
            if(i>=3){
                f[i]=min(f[i],f[i-3]+1);
            }
            if(i>=5){
                f[i]=min(f[i],f[i-5]+1);
            }
        }
        if(f[n]!=2e9){
            cout<<f[n];
        }else{
            cout<<-1;
        }
    }
    return 0;
}
