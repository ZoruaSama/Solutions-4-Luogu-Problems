#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
int mp[10][10];
bool vis[10][10]={0};
int xx[]={+1,0,-1,0};
int yy[]={0,+1,0,-1};
int minn=2e9;
//7 6 2 0 0 0 0 0 1 0 0 0 0 0 1 1 4 0 0 0 1 0 0 0 0 0 1 1 1 1 1 3 4 0 1 0 4 0 0 0 4 0 0 0
//15
void dfs(int x,int y,int hp,int time){
    if(time>minn){
        return ;
    }
    if(mp[x][y]==3){
        minn = min(minn,time);
        return ;
    }
    if(hp==1){
        return ;
    }
    for(int i=0;i<4;i++){
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx>0 && nx<=n && ny>0 && ny<=m && mp[nx][ny]!=0 && !vis[nx][ny]){
            vis[nx][ny]=true;
            dfs(nx,ny,hp-1,time+1);
            vis[nx][ny]=false;
                                //约束条件              限界条件
            if(mp[nx][ny]<0 && hp > 7 + mp[nx][ny] && hp-1 < abs(mp[nx][ny])){
                vis[nx][ny]=true;
                dfs(nx,ny,abs(mp[nx][ny]),time+12+2*mp[nx][ny]+1);
                vis[nx][ny]=false;
            }

        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==4){
                mp[i][j]=-6;
                for(int a=-2;a<=2;++a){
                    if(i+a>0 && i+a <= n && mp[i+a][j]==1){
                        mp[i+a][j]=min(mp[i+a][j],mp[i][j]+abs(a));
                    }
                    if(i+a>0 && i+a <= m && mp[i][j+a]==1){
                        mp[i][j+a]=min(mp[i][j+a],mp[i][j]+abs(a));
                    }
                }
             }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==2){
                dfs(i,j,6,0);
            }
        }
    }

    if(minn==2e9){
        minn=-1;
    }
    cout<<minn;
    return 0;
}
