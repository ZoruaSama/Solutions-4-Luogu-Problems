#include <iostream>
using namespace std;
int main() {
    int n,k,ans[100005]={0};
    cin>>n>>k;
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(k,i);j++){
                ans[i] += ans[i-j];
                ans[i] %= 100003;
        }
    }
    cout<<ans[n];
    return 0;
}