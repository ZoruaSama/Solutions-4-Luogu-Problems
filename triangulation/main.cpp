#include <iostream>
using namespace std;
int main() {
    int n=5;
    int t[8][8]={0};
    int v[8][8]={0};
    for(int i=1;i<=6;++i){
        for(int j=1;j<=3;++j){
            if(i+j<=6){
                v[i][i+j]=j;
                v[i+j][i]=j;
            }else{
                v[i][i+j-6]=j;
                v[i+j-6][i]=j;
            }
        }
    }
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;++i){
            int j=i+r-1;
            t[i][j]=t[i+1][j]+v[i-1][i]+v[i][j]+v[i-1][j];
            for(int k=i+1;k<i+r-1;k++){
                int u = t[i][k]+t[k+1][j]+v[i-1][k]+v[k][j]+v[i-1][j];
                if(u>t[i][j]){
                    t[i][j]=u;
                }
            }
        }
    }
    cout<<t[1][5]<<endl;
    return 0;
}
