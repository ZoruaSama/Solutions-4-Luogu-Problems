#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int r;
    int a[1000][1000]={0};
    int f[1000][1000]={0};
    cin>>r;
    for(int i=0;i<r;++i){
        for(int j=0;j<=i;++j){
            cin>>a[i][j];
        }
    }
    f[0][0]=a[0][0];
    f[1][0]=a[0][0]+a[1][0];
    f[1][1]=a[0][0]+a[1][1];
    for(int i=2;i<r;++i){
        for(int j=0;j<=i;++j){
            f[i][j]=a[i][j]+max(f[i-1][j-1],f[i-1][j]);
        }
    }
    int res=0;
    for(int j=0;j<r;j++){
        res=max(res,f[r-1][j]);
    }
    cout<<res;

    return 0;
}