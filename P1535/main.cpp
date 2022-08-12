#include <iostream>
#include <queue>
using namespace std;
struct node{
    int x,y,t;
};
int n,m,t;
int r1,c1,r2,c2;
int dp[101][101][16]={0}; // dp[i][j][k]dp[i][j][k]表示在第k分钟到达点(i,j)的方案数
char mp[101][101];
int xx[]={-1,0,+1,0};
int yy[]={0,+1,0,-1};
queue<node> q;
int main() {
    cin>>n>>m>>t;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>mp[i][j];
        }
    }
    cin>>r1>>c1>>r2>>c2;
    q.push(node{r1,c1,0});
    dp[r1][c1][0]=1;
    while(!q.empty()){
        if(q.front().t >=t){
            q.pop();
            continue ;
        }
        for(int i=0;i<4;++i){
            int nx=q.front().x+xx[i];
            int ny=q.front().y+yy[i];
            int nt=q.front().t+1;
            if(nx>=1 && ny>=1 && nx<=n && ny<=m && mp[nx][ny]=='.'){
                if(!dp[nx][ny][nt]){
                    q.push(node{nx,ny,nt});
                }
                dp[nx][ny][nt]+=dp[q.front().x][q.front().y][q.front().t];
            }
        }
        q.pop();
    }
    cout<<dp[r2][c2][t];
    return 0;
}
