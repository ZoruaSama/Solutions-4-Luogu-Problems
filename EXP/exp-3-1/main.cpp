#include <iostream>
#include <algorithm>
using namespace std;
int f[100][100]={0};
int r[100][100]={0};
void LCS(int i,int j,const string &x){
    if(i==0||j==0){
        return ;
    }
    if(r[i][j]==1){
        LCS(i-1,j-1,x);
        cout<<x[i];
    }else if(r[i][j]==2){
        LCS(i-1,j,x);
    }else{
        LCS(i,j-1,x);
    }
}
int main() {
    string a,b; //NOLINT
    cin>>a>>b;
    a=" "+a;
    b=" "+b;
    for(int i=1;i<a.length();++i){
        for(int j=1;j<b.length();++j){
            if(a[i] == b[j]){
                f[i][j]=f[i-1][j-1]+1;
                r[i][j]=1;
            }else if(f[i-1][j]>=f[i][j-1]){
                f[i][j]=f[i-1][j];
                r[i][j]=2;
            }else{
                f[i][j]=f[i][j-1];
                r[i][j]=3;
            }
        }
    }
    cout<<f[a.length()-1][b.length()-1]<<endl;
    LCS(a.length()-1,b.length()-1,a);
    return 0;
}
