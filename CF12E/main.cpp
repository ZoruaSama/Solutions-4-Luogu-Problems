#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1010];
int f[1010][1010];
void turn(){
    int c=a[1];
    for(int i=1;i<=n-2;++i){
        a[i]=a[i+1];
    }
    a[n-1]=c;
}
int main() {
    cin>>n;
    for(int i=1;i<=n-1;++i){
        a[i]=i;
    }
    for(int m=1;m<=n-1;++m){
        for(int i=1;i<=n-1;++i){
            f[m][i]=a[i];
        }
        f[m][n]=f[m][m];
        f[n][m]=f[m][m];
        f[m][m]=0;
        turn();
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<f[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
