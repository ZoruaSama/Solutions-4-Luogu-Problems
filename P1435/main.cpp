#include <iostream>
using namespace std;
int f[1010][1010]={0};
int main() {
    string a;
    cin>>a;
    string b=a;
    for(int i=0;i<a.length();++i){
        b[a.length()-i-1]=a[i];
    }

    a=" "+a;
    b=" "+b;
    for(int i=1;i<=a.length()-1;++i){
        for(int j=1;j<=b.length()-1;++j){
           if(a[i]==b[j]){
               f[i][j]=f[i-1][j-1]+1;
           } else{
               f[i][j]=max(f[i-1][j],f[i][j-1]);
           }
        }
    }
    cout<<a.length() - 1 - f[a.length()-1][b.length()-1];
    return 0;
}
