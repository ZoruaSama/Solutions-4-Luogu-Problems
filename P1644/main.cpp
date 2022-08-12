#include <iostream>
using namespace std;
int n,m;
int total=0;
int xx[]={+1,+2,+1,+2};
int yy[]={+2,+1,-2,-1};
bool vis[19][19]={1};
void dfs(int x,int y){
    if(x==m && y==n){
        total++;
        return ;
    }else{
        for(int i=0;i<4;++i){
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(nx>=0 && ny>=0 && nx<=m && ny<=n && !vis[nx][ny]){
                vis[nx][ny]=true;
                dfs(nx,ny);
                vis[nx][ny]=false;
            }
        }
    }
}
int main() {
    cin>>n>>m;
    dfs(0,0);
    cout<<total;
    return 0;
}
