#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m,n,k;
int mp[101][101];
int f[101][101][101];
vector<int> ans;
void dfs(int x,int y,int num){
    num*=mp[x][y];
    num%=k;
    if(x>m || y>n){
        return ;
    }
    if(x==m && y==n){
        ans.push_back(num);
        return ;
    }
    if(f[x][y][num]){
        return ;
    }
    f[x][y][num]=1;
    dfs(x+1,y,num);
    dfs(x,y+1,num);
}
int main() {
    cin>>m>>n>>k;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
        }
    }
    dfs(1,1,1);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    int size=ans.size();
    cout<<size<<endl;
    for(int i=0;i<size;++i){
        cout<<ans[i]<<' ';
    }
    return 0;
}
