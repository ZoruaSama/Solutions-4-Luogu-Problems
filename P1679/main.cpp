#include <iostream>
#include <cmath>
using namespace std;
int f[100010];
int m;
int main() {
    cin>>m;
    for(int i=1;i<=m;++i){
        f[i]=2e9;
    }
    for(int i=1;i<=(int)sqrt(sqrt(m));++i){
        for(int j=i*i*i*i;j<=m;++j){
            f[j]=min(f[j],f[j-i*i*i*i]+1);
        }
    }
    cout<<f[m];
    return 0;
}
