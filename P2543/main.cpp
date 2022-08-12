#include <iostream>
#include <algorithm>
using namespace std;
int f[10000][10000]={0};
int main() {
    string a,b; //NOLINT
    cin>>a>>b;
    a=" "+a;
    b=" "+b;
    for(int i=1;i<a.length();++i){
        for(int j=1;j<b.length();++j){
            if(a[i] == b[j]){
                f[i][j]=f[i-1][j-1]+1;
            }else if(f[i-1][j]>=f[i][j-1]){
                f[i][j]=f[i-1][j];
            }else{
                f[i][j]=f[i][j-1];
            }
        }
    }
    cout<<f[a.length()-1][b.length()-1]<<endl;
    return 0;
}
