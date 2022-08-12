#include <iostream>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn];
int f[32]; //最后一项第i位为1的最大子序列长度
int ans;
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        int k=1;
        for(int c=0;c<=30;++c){
            if((1<<c)&a[i]){
                k = max(k,f[c]+1);
            }
        }
        for(int c=0;c<=30;++c){
            if((1<<c)&a[i]){
                f[c] = max(f[c],k);
            }
        }
        ans=max(ans,k);
    }
    cout<<ans;
    return 0;
}
