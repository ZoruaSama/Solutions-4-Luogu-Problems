#include <iostream>
using namespace std;
int main() {
    int ans=0;
    bool f[1005]={false};
    int fm[]={0,1,2,3,5,10,20};
    int n[7];
    int maxn=0;
    f[0]=true;
    for(int i=1;i<=6;++i){
        cin>>n[i];
        maxn+=n[i]*fm[i];
    }
    for(int i=1;i<=6;++i){
        for(int j=1;j<=n[i];++j){
            for(int k=maxn;k>=0;--k){
                if(f[k] && k+fm[i]<=maxn){
                    f[k+fm[i]]=true;
                }
            }
        }
    }
    for(int i=1;i<=maxn;++i){
        if(f[i]) {
            ans++;
        }
    }
    cout<<"Total="<<ans;
    return 0;
}
