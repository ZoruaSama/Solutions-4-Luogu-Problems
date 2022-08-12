#include <iostream>
#include <algorithm>
using namespace std;
int x[100];
int f[100];
//O(n^2)
//O(nlogn)
// * 贪心+二分
// * 树状数组+离散化+前缀和
// * 单调栈维护

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i];
        f[i]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(x[i]>x[j]) f[i]=max(f[i],f[j]+1);
        }
    }
    int ans;
    for(int i=1;i<=n;++i){
        ans=max(f[i],ans);
    }
    cout<<ans;
    return 0;
}
