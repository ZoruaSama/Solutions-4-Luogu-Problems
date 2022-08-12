#include <iostream>
using namespace std;
int n,m,t;
int count=0;
int sx,sy,fx,fy;
int mp[6][6]={0};
void dfs(int x,int y){
    if(x==fx && y==fy){
        count++;
        return ;
    }else{
        static int xx[]={-1,0,+1,0};
        static int yy[]={0,-1,0,+1};
        for(int i=0;i<4;++i){
            int nx = x+xx[i];
            int ny = y+yy[i];
            if(nx >= 1 && ny>=1 && nx<=n && ny <= m && mp[nx][ny]!=1){
                mp[nx][ny]=1;
                dfs(nx,ny);
                mp[nx][ny]=0;
            }
        }
    }
}

int main() {

    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;

    for(int i=0;i<t;++i){
        int x,y;
        cin>>x>>y;
        mp[x][y]=1;
    }
    mp[sx][sy]=1;
    dfs(sx,sy);
    cout<<count;
    return 0;
}
