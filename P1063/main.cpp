#include <iostream>
using namespace std;
const int maxn=101;
int n;
int a[maxn*2];
int b[maxn*2];
int f[maxn*2][maxn*2];
int cal(int a_,int b_,int c_){
    return a[a_]*a[b_]*b[c_];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;++i){
        b[i]=a[i+1];
        b[i+n]=a[i+1+n];
    }
    for(int j=2;j<=n*2;++j){
        for(int i=1;i+j<=n*2;++i){
            for(int k=1;k<j;++k){
                f[i][j]=max(f[i][j],f[i][k]+f[i+k][j-k]+cal(i,i+k,i+j-1));
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,f[i][n]);
    }
    cout<<ans;
    return 0;
}
