#include <iostream>
int mp[1001][1001];
bool vis[1001][1001]={false};
int re[1001][1001][3];
using namespace std;
int n,m;
void dfs(int x,int y,int score,int direc){
    if(re[x][y][direc]!=0 && score <=re[x][y][direc]){
        return ;
    }else{

    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>mp[i][j];
        }
    }
    // 0 RIGHT
    // 1 UP
    // 2 DOWN
    dfs(1,1,0,2);
    dfs(1,1,0,0);

    return 0;
}
