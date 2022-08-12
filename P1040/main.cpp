#include <iostream>
using namespace std;
const int maxn=31;
int f[maxn][maxn];
int r[maxn][maxn];
int n;
int s[maxn];
void prt(int x,int y){
    if(r[x][y]==0){
        return ;
    }
    cout<<r[x][y]<<' ';
    prt(x,r[x][y]-1);
    prt(r[x][y]+1,y);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
    }
    for(int i=1;i<=n;++i){
        f[i][0]=1;
        f[i][1]=s[i];
        r[i][i]=i;
    }
    for(int j=2;j<=n;++j){
        for(int i=1;i+j-1<=n;++i){
            for(int k=0;k<j;++k){//选择一个根
                int res=f[i][k]*f[i+k+1][j-k-1]+f[i+k][1];
                if(f[i][j]<res){
                    f[i][j]=res;
                    r[i][i+j-1]=i+k;
                }
            }
        }
    }
    cout<<f[1][n]<<endl;
    prt(1,n);
    return 0;
}
