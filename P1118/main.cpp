#include <iostream>
using namespace std;
int n,sum,yh[20][20]={0},vis[20]={0},a[20];
bool flag=false;
//杨辉三角
void dfs(int p,int s){
    if(flag) return ;
    if(s>sum) return ;
    if(p>n){
        if(s==sum){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            flag = true;
        }
        return ;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                a[p]=i;
                vis[i]=1;
                dfs(p+1,s+i*yh[n][p]);
                vis[i]=0;
            }
        }
    }
}
int main() {
    cin>>n>>sum;
    yh[1][1]=1;
    for(int i=2;i<=13;i++){
        for(int j=1;j<=i;j++){
            yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
        }
    }
    dfs(1,0);
    return 0;
}
