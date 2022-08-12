#include <iostream>
using namespace std;
int n,a,ans;
int f[1001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        for(int j=i;j>=1;j--){
            f[j]=max(f[j],f[j-1]+(a==j?1:0));
        }
    }
    for(int i=0;i<=n;++i) {
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}