#include <iostream>
using namespace std;
int main() {
    int n;
    long long f[101][101]={0};
    // f[i][j]，i表示栈内数字的个数，j表示未进栈数字的个数，f计当前状态下有几种情况
    // f[i][j] = f[i-1][j] + f[i+1][j-1] (i>=1)
    // f[0][j]=f[1][j-1] (i=0)
    // f[i][0]=1 栈外没有数字只能出栈
    cin>>n;

    for(int i=0;i<=n;++i){
        f[i][0]=1;
    }
    for(int j=1;j<=n;++j){
        for(int i=0;i<=n;++i){
            if(i==0){
                f[i][j] = f[1][j-1];
                f[i][j]%=100;
            }
            else{
                f[i][j] = f[i-1][j] + f[i+1][j-1];
                f[i][j]%=100;
            }
        }
    }
    cout<<f[0][n];
    return 0;
}