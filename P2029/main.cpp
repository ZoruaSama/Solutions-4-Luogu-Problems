#include <iostream>
using namespace std;
int n,t;
const int maxn=5001;
int  s[maxn],b[maxn];
int  q[maxn];
int  f[maxn][maxn];

int main() {
    cin>>n>>t;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        q[i]=q[i-1]+s[i];
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];
    }
    //f[i][j] 踩了i个 踏准j个
    for(int i=1;i<=n;++i){
        f[i][0]=f[i-1][0]-s[i];
        for(int j=1;j<=i;++j){
            f[i][j]=f[i-1][j-1]+s[i]+((j%t==0)?b[i]:0);
            f[i][j]=max(f[i][j],f[i-1][j]-s[i]);
        }
    }
    int ans=0;
    for(int i=0;i<=n;++i){
        ans=max(ans,f[n][i]);
    }
    cout<<ans;
    return 0;
}
