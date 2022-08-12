#include <iostream>
using namespace std;
int sum[510]={0};//前缀和
int me[510][510][510]={0};
int b[501];
int dfs(int x,int y,int p){
    int res=2e9;
    if(me[x][y][p]!=0) return me[x][y][p];
    if(p==0){
        return me[x][y][p] = 0;
    }
    if(p==1){
        return me[x][y][p] = sum[y]-sum[x-1];
    }
    for(int i=x;i<y;++i){
        int ans = max(dfs(x,i,1),dfs(i+1,y,p-1));
        if(res>ans){
            res=ans;
        }
    }
    return me[x][y][p] = res;
}

int main() {
    int m,k;
    cin>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>b[i];
        sum[i]=sum[i-1]+b[i];
    }
    int ans = dfs(1,m,k);
    cout<<ans;
    return 0;
}