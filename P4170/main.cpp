#include <iostream>
using namespace std;
const int maxn=51;
int f[maxn][maxn];
int main() {
    string s;
    cin>>s;
    int n=s.length();
    for(int i=1;i<=n;++i){
        f[i][1]=1;
    }
    for(int j=2;j<=n;++j){
        for(int i=1;i+j-1<=n;++i){
            if(s[i-1]==s[i+j-1-1]){
                f[i][j]=min(f[i][j-1],f[i+1][j-1]);
            }else{
                f[i][j]=2e9;
                for(int k=1;k<j;++k){
                    f[i][j]=min(f[i][j],f[i][k]+f[i+k][j-k]);
                }
            }
        }
    }
    cout<<f[1][n];
    return 0;
}
