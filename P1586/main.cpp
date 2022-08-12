#include <iostream>
#include <cmath>
using namespace std;
int t,n;
const int maxn=32768+10;
int f[maxn][5];
int main() {
    cin>>t;
    f[0][0]=1;
    for(int i=1;i<=(int)sqrt(maxn);++i){
        for(int j=i*i;j<=maxn;++j){
            for(int k=1;k<=4;++k){
                f[j][k]+=f[j-i*i][k-1];
            }
        }
    }

    while(t--){
        cin>>n;
        cout<<f[n][1]+f[n][2]+f[n][3]+f[n][4]<<endl;
    }

    return 0;
}
