#include <iostream>
#include <vector>
using namespace std;
int mp[7][7];
int n,m;
int xx[]={+1,0,-1,0,-1,+1,-1,+1};
int yy[]={0,+1,0,-1,-1,+1,+1,-1};
int maxn=-1;
int vis[7][7]={0};
using namespace std;
void dfs(int x,int y,int sum){
    if(x==n+1){
       maxn=max(sum,maxn);
       return ;
    }
    if(y==m+1){
        dfs(x+1,1,sum);
        return ;
    }
    if(vis[x][y]==0) {
        vis[x][y] ++;
        for (int i = 0; i < 8; ++i) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
                vis[nx][ny]++;
            }
        }
        dfs(x, y + 1, sum + mp[x][y]);
        for (int i = 0; i < 8; ++i) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
                vis[nx][ny]--;
            }
        }
        vis[x][y]--;
    }
    dfs(x,y+1,sum);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        maxn=-1;
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>mp[i][j];
            }
        }
        dfs(1,1,0);
        cout<<maxn<<endl;
    }
    return 0;
}
